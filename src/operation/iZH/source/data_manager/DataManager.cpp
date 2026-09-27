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
#include "DataManager.hpp"

#include "Utility.hpp"
#include "ZHInterface.hpp"

namespace izh {

// public

void DataManager::initInst()
{
  if (_dm_instance == nullptr) {
    _dm_instance = new DataManager();
  }
}

DataManager& DataManager::getInst()
{
  if (_dm_instance == nullptr) {
    ZHLOG.error(Loc::current(), "The instance not initialized!");
  }
  return *_dm_instance;
}

void DataManager::destroyInst()
{
  if (_dm_instance != nullptr) {
    delete _dm_instance;
    _dm_instance = nullptr;
  }
}

// function

void DataManager::input(std::map<std::string, std::any>& config_map)
{
  Monitor monitor;
  ZHLOG.info(Loc::current(), "Starting...");

  ZHI.input(config_map);
  buildConfig();
  printConfig();

  ZHLOG.info(Loc::current(), "Completed", monitor.getStatsInfo());
}

void DataManager::output()
{
  Monitor monitor;
  ZHLOG.info(Loc::current(), "Starting...");

  ZHI.output();

  ZHLOG.info(Loc::current(), "Completed", monitor.getStatsInfo());
}

// private

DataManager* DataManager::_dm_instance = nullptr;

#if 1  // build

void DataManager::buildConfig()
{
  /////////////////////////////////////////////
  // **********        ZH         ********** //
  _config.temp_directory_path = std::filesystem::absolute(_config.temp_directory_path);
  _config.temp_directory_path += "/";
  _config.log_file_path = _config.temp_directory_path + "zh.log";
  // **********    DataManager    ********** //
  _config.dm_temp_directory_path = _config.temp_directory_path + "data_manager/";
  // **********  AntennaChecker   ********** //
  _config.ac_temp_directory_path = _config.temp_directory_path + "antenna_checker/";
  // **********   DefFlattener    ********** //
  _config.df_temp_directory_path = _config.temp_directory_path + "def_flattener/";
  // **********  FillerInserter   ********** //
  _config.fi_temp_directory_path = _config.temp_directory_path + "filler_inserter/";
  // **********  MetalInserter    ********** //
  _config.mi_temp_directory_path = _config.temp_directory_path + "metal_inserter/";

  /////////////////////////////////////////////
  // **********        ZH         ********** //
  ZHUTIL.removeDir(_config.temp_directory_path);
  ZHUTIL.createDir(_config.temp_directory_path);
  ZHUTIL.createDirByFile(_config.log_file_path);
  // **********    DataManager    ********** //
  ZHUTIL.createDir(_config.dm_temp_directory_path);
  // **********  AntennaChecker   ********** //
  ZHUTIL.createDir(_config.ac_temp_directory_path);
  // **********   DefFlattener    ********** //
  ZHUTIL.createDir(_config.df_temp_directory_path);
  // **********  FillerInserter   ********** //
  ZHUTIL.createDir(_config.fi_temp_directory_path);
  // **********  MetalInserter    ********** //
  ZHUTIL.createDir(_config.mi_temp_directory_path);
  /////////////////////////////////////////////
  ZHLOG.openLogFileStream(_config.log_file_path);
}

#endif

#if 1  // exhibit

void DataManager::printConfig()
{
  /////////////////////////////////////////////
  // **********        ZH         ********** //
  ZHLOG.info(Loc::current(), ZHUTIL.getSpaceByTabNum(0), "ZH_CONFIG_INPUT");
  ZHLOG.info(Loc::current(), ZHUTIL.getSpaceByTabNum(1), "temp_directory_path");
  ZHLOG.info(Loc::current(), ZHUTIL.getSpaceByTabNum(2), _config.temp_directory_path);

  // **********        ZH         ********** //
  ZHLOG.info(Loc::current(), ZHUTIL.getSpaceByTabNum(0), "ZH_CONFIG_BUILD");
  ZHLOG.info(Loc::current(), ZHUTIL.getSpaceByTabNum(1), "log_file_path");
  ZHLOG.info(Loc::current(), ZHUTIL.getSpaceByTabNum(2), _config.log_file_path);
  // **********    DataManager    ********** //
  ZHLOG.info(Loc::current(), ZHUTIL.getSpaceByTabNum(1), "DataManager");
  ZHLOG.info(Loc::current(), ZHUTIL.getSpaceByTabNum(2), _config.dm_temp_directory_path);
  // **********  AntennaChecker   ********** //
  ZHLOG.info(Loc::current(), ZHUTIL.getSpaceByTabNum(1), "AntennaChecker");
  ZHLOG.info(Loc::current(), ZHUTIL.getSpaceByTabNum(2), _config.ac_temp_directory_path);
  // **********   DefFlattener    ********** //
  ZHLOG.info(Loc::current(), ZHUTIL.getSpaceByTabNum(1), "DefFlattener");
  ZHLOG.info(Loc::current(), ZHUTIL.getSpaceByTabNum(2), _config.df_temp_directory_path);
  // **********  FillerInserter   ********** //
  ZHLOG.info(Loc::current(), ZHUTIL.getSpaceByTabNum(1), "FillerInserter");
  ZHLOG.info(Loc::current(), ZHUTIL.getSpaceByTabNum(2), _config.fi_temp_directory_path);
  // **********  MetalInserter    ********** //
  ZHLOG.info(Loc::current(), ZHUTIL.getSpaceByTabNum(1), "MetalInserter");
  ZHLOG.info(Loc::current(), ZHUTIL.getSpaceByTabNum(2), _config.mi_temp_directory_path);
  /////////////////////////////////////////////
}

#endif

}  // namespace izh
