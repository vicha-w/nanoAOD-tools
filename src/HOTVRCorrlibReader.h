#ifndef HOTVRCorrlibReader_H
#define HOTVRCorrlibReader_H

#include "correction.h"

#include <string>
#include <iostream>

class HOTVRCorrlibReader
{
    private:
        std::unique_ptr<correction::CorrectionSet> correctionSet_;
    public:
        HOTVRCorrlibReader()
        {
        }
        
        void loadCorrections(const char* filePath)
        {
            try {
                correctionSet_ = std::move(correction::CorrectionSet::from_file(std::string(filePath)));
            } catch (const std::runtime_error& e) {
                std::cerr << "Error loading correction file: " << e.what() << std::endl;
                std::cerr << "File: " << filePath << std::endl;
                throw;
            }
        }
        
        void printTypeInfo(std::string type)
        {
            if (not correctionSet_) throw std::runtime_error("No HOTVR corrections have been loaded!");
            auto corr = correctionSet_->at(type);
            std::cout<<"info for syst '"<<type<<"'"<<std::endl;
            std::cout<<"  name: "<<corr->name()<<std::endl;
            std::cout<<"  description: "<<corr->description()<<std::endl;
            std::cout<<"  inputs: "<<corr->inputs().size()<<std::endl;
            for (const auto input: corr->inputs())
            {
                std::cout<<"     "<<input.name()<<" ("<<input.typeStr()<<")"<<std::endl;
            }
        }
        
        void printTypes()
        {
            if (not correctionSet_) throw std::runtime_error("No HOTVR corrections have been loaded!");
            std::cout<<"loaded correction types: ";
            for (auto corr: *correctionSet_)
            {
                std::cout<<corr.first<<", ";
            }
            std::cout<<std::endl;
        }

        double evaluateHOTVRSF(std::string type, float pt, std::string syst)
        {
            if (not correctionSet_) throw std::runtime_error("No HOTVR corrections have been loaded!");
            return correctionSet_->at(type)->evaluate({pt,syst});
        }
    
};

#endif
