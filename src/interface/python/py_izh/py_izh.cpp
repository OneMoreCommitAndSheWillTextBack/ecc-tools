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
#include "py_izh.h"

#include <string>

#include "ZHInterface.hpp"

namespace python_interface {

bool insert_filler(const std::string& filler)
{
  std::map<std::string, std::any> config_map;
  if (!filler.empty()) {
    config_map["-filler"] = filler;
  }
  ZHI.insertFiller(config_map);
  return true;
}

bool check_antenna(const std::string& report_dir)
{
  std::map<std::string, std::any> config_map;
  if (!report_dir.empty()) {
    config_map["-report_dir"] = report_dir;
  }
  ZHI.checkAntenna(config_map);
  return true;
}

bool insert_metal(const std::string& min_fill_layer, const std::string& max_fill_layer)
{
  std::map<std::string, std::any> config_map;
  if (!min_fill_layer.empty()) {
    config_map["-min_fill_layer"] = min_fill_layer;
  }
  if (!max_fill_layer.empty()) {
    config_map["-max_fill_layer"] = max_fill_layer;
  }
  ZHI.insertMetal(config_map);
  return true;
}

bool def_flatten(const std::string& hierarchy)
{
  std::map<std::string, std::any> config_map;
  config_map["-hierarchy"] = hierarchy;
  ZHI.flattenDef(config_map);
  return true;
}

}  // namespace python_interface
