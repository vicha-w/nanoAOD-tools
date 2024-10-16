import os, re, sys
import subprocess
import argparse
import yaml
import stat

parser = argparse.ArgumentParser()

parser.add_argument('--sgn', dest='sgn', action='store_true', help='Signal', default=False)
parser.add_argument('--relwidth', dest='relwidth', type=str, help='Relative Reso Width', default='0')
parser.add_argument('--year', dest='year', type=str, help='Year', default='2017')
parser.add_argument('--isData', dest='isData', action='store_true', help='Data', default=False)


args = parser.parse_args()


listOfDataSets = []
listOutputDir = []
yaml_file_dict = {}

ERAS = {
    '2018': ['A', 'B', 'C', 'D'], '2017': ['B', 'C', 'D', 'E', 'F'],
    '2016': ['F', 'G', 'H'],
    '2016preVFP': ['B', 'C', 'D', 'E', 'F'], #'B"
    '2022': ['C', 'D'], '2022EE': ['E', 'F', 'G']
} # ,

data_sample = ''

MASS_VALUES = ['2000', '500', '1000']#['500', '750', '1000', '1250', '1500', '1750', '2000', '2500', '3000', '4000'] #
relwidth_values = ['4']#,'10','20','50']

with open('file_list.yaml') as yaml_f:
    try:
        yaml_file_dict = yaml.safe_load(yaml_f)
    except yaml.YAMLError as exc:
        print(exc)

if args.sgn:
    for width in relwidth_values:
        for mass in MASS_VALUES:
            listOfDataSets.append(yaml_file_dict['sgn'][args.year][0].replace("WIDTH", width).replace("MASS", mass))
            listOutputDir.append(yaml_file_dict['sgn'][args.year][1].replace("WIDTH", width).replace("MASS", mass))
elif args.isData: 
    for data_sample in yaml_file_dict['data'][args.year].keys():
        for era in ERAS[args.year]:
            listOfDataSets.append(yaml_file_dict['data'][args.year][data_sample][0]+'_'+era)
            listOutputDir.append(yaml_file_dict['data'][args.year][data_sample][1]+'_'+era)
else:
    for sample in yaml_file_dict['bkg'][args.year].keys():
        listOfDataSets.append(yaml_file_dict['bkg'][args.year][sample][0])
        listOutputDir.append(yaml_file_dict['bkg'][args.year][sample][1])  

print(listOfDataSets)
print(listOutputDir)


# --- EXECUTABLES FILES
current_dir = os.getcwd()
executables_dir = os.path.join(current_dir, 'executable_files', args.year)
if not os.path.exists(executables_dir):
    os.makedirs(executables_dir)
os.chmod(executables_dir, stat.S_IRWXU | stat.S_IRWXG | stat.S_IRWXO)  # equivalent to chmod 777
subprocess.call(['chmod', '-R', 'a+w+x+r', executables_dir])

with open('executable_jobs_hotvr_tmp.sh', 'r') as exe_f_tmp:
    exe_file = exe_f_tmp.read()
exe_file=exe_file.replace('YEAR', args.year)

executable_name = 'executable_jobs_' + args.year + '_hotvr.sh'

with open(executables_dir + '/' + executable_name, 'w') as exe_f:
    exe_f.write(exe_file)
os.chmod(executables_dir + '/' + executable_name, 0o777)   
# ----


# ---- CONDOR FILES
with open('condor_submission', 'r') as condor_f:
    condor_sub_file = condor_f.read()
    executable_name = 'executable_jobs_' + args.year + '_hotvr.sh'
    condor_sub_file = condor_sub_file.replace('EXE', executables_dir + '/' + executable_name)

command_str, files_str = '', ''
command_dict = dict()

CONDOR_SUBMIT_FILES_DIR = '{}/condor_submit_files'.format(os.getcwd())
if not os.path.isdir(CONDOR_SUBMIT_FILES_DIR):
    print('Making dirs: \n{}'.format(CONDOR_SUBMIT_FILES_DIR))
    os.makedirs(CONDOR_SUBMIT_FILES_DIR)

CONDOR_REPO_LOGFILE = '/nfs/dust/cms/user/gmilella/ttX_ntuplizer/log_files/'
NFS_OUTPUT_REPO = '/nfs/dust/cms/user/gmilella/ttX_ntuplizer'

output_dir = "bkg_{}_hotvr".format(args.year)
if args.isData: output_dir = "data_{}_hotvr".format(args.year)
elif args.sgn: output_dir = "sgn_{}_central_hotvr".format(args.year)

#command_list = condor_sub_file
#print(command_list)

batch_number = 1 
batch_count = 0

files_batches = {}
files_batch_number = 0
total_files = 0 # upper limit on 50k files --> it will result in more than 5k jobs
total_files_in_condor_job = 0

files_for_lxplus = ''

processes_list, processes_dirs_list = [], []

for iprocess, process_dir in enumerate(listOfDataSets):
    processes_list.append(listOutputDir[iprocess])
    processes_dirs_list.append(process_dir)

for process, process_dir in zip(processes_list, processes_dirs_list):
    if 'DoubleLepton' in process: trigger = 'emu'
    if 'DoubleEG' in process: trigger = 'ee'
    if 'DoubleMuon' in process or 'Muon' in process: trigger = 'mumu'

    if os.path.exists('/pnfs/desy.de/cms/tier2/store/user/gmilella/{}'.format(process_dir)):

        if process not in files_batches.keys(): files_batches[process] = {}
        files_batch_number += 1
        command_str = ''

        for root, subdirs, files in os.walk('/pnfs/desy.de/cms/tier2/store/user/gmilella/{}'.format(process_dir)):
            if len(files) != 0: 
                print('Dataset {}, number of files {}'.format(process_dir, len(files)))

                for ifile, file in enumerate(files):
                    if '.root' in file:
                        file_path = os.path.join(root, file)
                        total_files += 1

                        files_str += " -i {} ".format(file_path)
                        if ifile % 3 == 0: #processising more file in one single condor job
                            files_batch_number += 1
                            files_str = " -i {} ".format(file_path)
                        files_batches[process][files_batch_number] = files_str

                    files_for_lxplus += '{}/{} \n'.format(root.split("/pnfs/desy.de/cms/tier2", 1)[1], file)

        for files_batches_per_process in files_batches[process]:
            command_str += '\narguments = " '
            
            command_str += files_batches[process][files_batches_per_process]

            command_str += ' {}/{}/{} '.format(NFS_OUTPUT_REPO, output_dir, process)
            if args.sgn:
                command_str += ' --isSignal "'
            elif args.isData:
                command_str += ' --isData "'
            else: command_str += ' "'
    
            command_str += "\nOutput = {}{}/{}/log/log_{}$(Cluster).$(Process).out".format(CONDOR_REPO_LOGFILE, output_dir, process, process)
            command_str += "\nError = {}{}/{}/log/log_{}$(Cluster).$(Process).err".format(CONDOR_REPO_LOGFILE, output_dir, process, process)
            command_str += "\nLog = {}{}/{}/log/log_{}$(Cluster).$(Process).log".format(CONDOR_REPO_LOGFILE, output_dir, process, process)
            # command_str += '\n+MyProject = "cms"\nqueue\n'
            command_str += '\nqueue\n'

        base_log_path = "{}{}/{}".format(CONDOR_REPO_LOGFILE, output_dir, process, process) 

        if not os.path.isdir(base_log_path): 
            print('Making dirs: \n{}'.format(base_log_path))
            os.makedirs(base_log_path)
        if not os.path.isdir(base_log_path + '/log'):
            os.makedirs(base_log_path + '/log')
            print('Making dirs: \n{}'.format(base_log_path + '/log'))

        if not os.path.isdir(os.path.join(NFS_OUTPUT_REPO, "{}/{}".format(output_dir, process))):
            print('Making dir: {}'.format(os.path.join(NFS_OUTPUT_REPO, "{}/{}".format(output_dir, process))))
            os.makedirs(os.path.join(NFS_OUTPUT_REPO, "{}/{}".format(output_dir, process)))

        if args.sgn: condor_out_name = 'condor_submission_sgn_new_{}_{}.sub'.format(process, args.year)
        elif args.isData: condor_out_name = 'condor_submission_data_new_{}.sub'.format(process)
        else: condor_out_name = 'condor_submission_bkg_new_{}.sub'.format(process)

        with open('{}/{}'.format(CONDOR_SUBMIT_FILES_DIR, condor_out_name), 'w+') as condor_f_new: 
            condor_f_new.write(condor_sub_file)
            condor_f_new.write(command_str)  

    else:
        print("Files not found in {}".format('/pnfs/desy.de/cms/tier2/store/user/gmilella/{}'.format(process_dir)))
        continue

print('Files in total: {}'.format(total_files))

with open('files_for_lxplus.txt', 'w') as file:
    file.write(files_for_lxplus)
