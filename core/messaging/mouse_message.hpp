#pragma once
#include"wilo_message.hpp"
#include "MouseCodes.hpp"
#include"KeyCodes.hpp"
#include"wilo_dev_core.hpp"
namespace wilo{


    class MouseMessage: public Message{
        public:
            struct Info{
                std::optional<double> xPos;
                std::optional<double> yPos;
                std::optional<double> xScroll_Offset;
                std::optional<double> yScroll_Offset;
                std::optional<MouseButton> button;
                std::optional<uint16_t> mod_bundle;
                bool hasModifier(KeyModifier mod){
                    return (mod_bundle.value()|mod)!=0;
                }
                std::string unpackModBundleName(){
                        std::stringstream name;
                        name<<"|";
                    if (mod_bundle.has_value()){
                        if (mod_bundle.value()&KeyModifier::ALT)
                            name<<"ALT|";
                        if (mod_bundle.value()&KeyModifier::SHIFT)
                            name<<"SHIFT|";
                        if (mod_bundle.value()&KeyModifier::SUPER)
                            name<<"SUPER|";
                    }

                    return name.str();

                }
            };
            MouseMessage(MessageType type, MouseMessage::Info info);
            std::string toString() const override ;
            MessageType getType() const override ;
            Info getInfo();
        private:
            Info m_info;
            MessageType m_type;
            std::string m_name;

    };


}