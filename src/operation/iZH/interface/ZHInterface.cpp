// ***************************************************************************************
// Copyright (c) 2023-2025 Peng Cheng Laboratory
// Copyright (c) 2023-2025 Institute of Computing Technology, Chinese Academy of Sciences
// Copyright (c) 2023-2025 Beijing Institute of Open Source Chip
//
// iEDA is licensed under Mulan PSL v2.
// You can use this software according to the terms and conditions of the Mulan PSL v2.
// You may obtain a copy of Mulan PSL v2 at:
// http://license.coscl.org.cn/MulanPSL2
//
// THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
// EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
// MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
//
// See the Mulan PSL v2 for more details.
// ***************************************************************************************
#include "ZHInterface.hpp"

#include "AntennaChecker.hpp"
#include "DataManager.hpp"
#include "DefFlattener.hpp"
#include "FillerInserter.hpp"
#include "Logger.hpp"
#include "MetalInserter.hpp"
#include "Monitor.hpp"
#include "Utility.hpp"

namespace izh {

// public

void ZHInterface::destroyInst()
{
  if (_zh_interface_instance != nullptr) {
    delete _zh_interface_instance;
    _zh_interface_instance = nullptr;
  }
}

#if 1  // 外部调用ZH的API

#if 1  // iZH

void ZHInterface::initZH(std::map<std::string, std::any> config_map)
{
  Logger::initInst();
  // clang-format off
  ZHLOG.info(Loc::current(), ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
  ZHLOG.info(Loc::current(), "___________  ___________   _____________________________________ ");
  ZHLOG.info(Loc::current(), "___(_)__   |/  /_____  /   __  ___/__  __/__    |__  __ \\__  __/");
  ZHLOG.info(Loc::current(), "__  /__  /|_/ /___ _  /    _____ \\__  /  __  /| |_  /_/ /_  /   ");
  ZHLOG.info(Loc::current(), "_  / _  /  / / / /_/ /     ____/ /_  /   _  ___ |  _, _/_  /     ");
  ZHLOG.info(Loc::current(), "/_/  /_/  /_/  \\____/      /____/ /_/    /_/  |_/_/ |_| /_/     ");
  ZHLOG.info(Loc::current(), ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
  // clang-format on
  ZHLOG.printLogFilePath();
  //////////////////////////////////////////////////////
  //////////////////////////////////////////////////////
  //////////////////////////////////////////////////////
  Monitor monitor;
  ZHLOG.info(Loc::current(), "Starting...");

  DataManager::initInst();
  ZHDM.input(config_map);

  ZHLOG.info(Loc::current(), "Completed", monitor.getStatsInfo());
}

void ZHInterface::insertFiller(std::map<std::string, std::any> config_map)
{
  FillerInserter::initInst();
  ZHFI.insert(config_map);
  FillerInserter::destroyInst();
}

void ZHInterface::insertMetal(std::map<std::string, std::any> config_map)
{
  MetalInserter::initInst();
  ZHMI.insert(config_map);
  MetalInserter::destroyInst();
}

void ZHInterface::checkAntenna(std::map<std::string, std::any> config_map)
{
  AntennaChecker::initInst();
  ZHAC.check(config_map);
  AntennaChecker::destroyInst();
}

void ZHInterface::flattenDef(std::map<std::string, std::any> config_map)
{
  DefFlattener::initInst();
  ZHDF.flatten(config_map);
  DefFlattener::destroyInst();
}

void ZHInterface::destroyZH()
{
  Monitor monitor;
  ZHLOG.info(Loc::current(), "Starting...");

  ZHDM.output();
  DataManager::destroyInst();

  ZHLOG.info(Loc::current(), "Completed", monitor.getStatsInfo());

  ZHLOG.printLogFilePath();
  // clang-format off
  ZHLOG.info(Loc::current(), ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
  ZHLOG.info(Loc::current(), "___________  ___________   _____________________   _____________________  __ ");
  ZHLOG.info(Loc::current(), "___(_)__   |/  /_____  /   ___  ____/___  _/__  | / /___  _/_  ___/__  / / / ");
  ZHLOG.info(Loc::current(), "__  /__  /|_/ /___ _  /    __  /_    __  / __   |/ / __  / _____ \\__  /_/ / ");
  ZHLOG.info(Loc::current(), "_  / _  /  / / / /_/ /     _  __/   __/ /  _  /|  / __/ /  ____/ /_  __  /   ");
  ZHLOG.info(Loc::current(), "/_/  /_/  /_/  \\____/      /_/      /___/  /_/ |_/  /___/  /____/ /_/ /_/   ");
  ZHLOG.info(Loc::current(), ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
  // clang-format on
  Logger::destroyInst();
}

#endif

#endif

#if 1  // ZH调用外部的API

#if 1  // TopData

#if 1  // input

void ZHInterface::input(std::map<std::string, std::any>& config_map)
{
  wrapConfig(config_map);
}

void ZHInterface::wrapConfig(std::map<std::string, std::any>& config_map)
{
  ZHDM.getConfig().temp_directory_path = ZHUTIL.getConfigValue<std::string>(config_map, "-temp_directory_path", "./zh_temp_directory");
}

#endif

#if 1  // output

void ZHInterface::output()
{
}

#endif

#endif

#endif

// private

ZHInterface* ZHInterface::_zh_interface_instance = nullptr;

}  // namespace izh
