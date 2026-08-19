#pragma once

#include <tuple>
#include <list>
#include <string>

#include "CommandParsing.h"

template<typename... PacketTypes>
class CommandProcessor {
public:
  std::tuple<std::list<void(*)(const PacketTypes&)>...> handlers;

  CommandProcessor() : handlers(std::tuple<std::list<void(*)(const PacketTypes&)>...>()) {};

  template<typename PacketType>
  void addHandler(void(*handler)(const PacketType&));

  void processCommand(const std::string& command_str);
};

template<typename... PacketTypes>
template<typename PacketType>
void CommandProcessor<PacketTypes...>::addHandler(void(*handler)(const PacketType&)) {
  std::list<void(*)(const PacketType&)>* packet_list = &std::get<std::list<void(*)(const PacketType&)>>(handlers);
  packet_list->emplace_front(handler);
}

template<typename... PacketTypes>
void CommandProcessor<PacketTypes...>::processCommand(const std::string& command_str) {
    (
        [&] {
            if (startsWith(PacketTypes::command_name, command_str)) {
                PacketTypes packet = PacketTypes(command_str);
                
                std::list<void(*)(const PacketTypes&)>* handler_list = &std::get<std::list<void(*)(const PacketTypes&)>>(handlers);
                for (void(*handler)(const PacketTypes&) : *handler_list) {
                    handler(packet);
                }

                return true;
            } else {
                return false;
            }
        }()
    || ...);
}