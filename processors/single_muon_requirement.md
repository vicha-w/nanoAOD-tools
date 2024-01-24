Single-muon preselection requirements
- Muon tight ID (AN2017/006)
- Muon with pT > 55, abs(eta) < 2.4 (JME-18-002)
- abs(muon dxy) < 0.2, abs(muon dz) < 0.5 (AN2018/107)
- Electron pT > 10, abs(eta) < 2.5 (AN2017/006, for veto requirements, adding both loose and veto electrons)
- AK4 jets with loose ID (AN2018/103, AN2017/006)
    - Since UL does not have loose jet ID, this effectively means accepting all jets.
- AK4 jet pT > 30, abs(eta) < 2.4 (JME-18-002)
- AK8 jets with NO jet ID requirement 
    - Jet ID requirement is not clear from JME-18-002 and AN2018/103, accepting all jets for now.
- AK8 jet pT > 200, abs(eta) < 2.4 (JME-18-002)
- b-tagged jets with pT > 30, abs(eta) < 2.4
- HOTVR jet pT > 200 abs(eta) < 2.4 (following AK8 requirement in JME-18-002)
- HOTVR subjet pT > 30, abs(eta) < 2.4 (old requirement in nanoAOD-tools, no requirement for HOTVR mentioned anywhere, we might not need this in SF measurement)
- MET pT >= 50 (JME-18-002)
- Passes HLT_Mu50_v trigger OR HLT_TkMu50_v trigger (AN2018/103)

To be run in event loop
- Event passes MET filters (AN2017/006, recorded at processor level)
- Exactly one muon (JME-18-002)
- Muon PF-based combined relative isolation with Delta_beta correction to be smaller than 0.05 (pfRelIso04_all < 0.05?) (AN2018/107)
- Muon deltaR between the muon and nearest AK4 jet > 0.4 OR the perpendicular component of the muon pT with respect to the nearest AK4 jet, pT_rel > 25 GeV (JME-18-002)
- Electron veto (AN2017/006)
- b-jet in the same hemisphere as muon within DeltaPhi < 2 (AN2018/103)
- At least one fat jet away from muon with DeltaPhi > 2 (JME-18-002)
- Two or more AK4 jets, at least one b-jet (JME-18-002)
- Event passes MET filters (AN2017/006, recorded at processor level)
- leptonic W pT > 250 GeV (JME-18-002, AN2017/006, recorded at processor level)

Removed
- Muon miniPFRelIso_all < 0.10 (appears in NanoHRT-tools code, not clear from JME-18-002)

Unavailable cuts we do not have right now
- Photon and tau veto (AN2017/006)