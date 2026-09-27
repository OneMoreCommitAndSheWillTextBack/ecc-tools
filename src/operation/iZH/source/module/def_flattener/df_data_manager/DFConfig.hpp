// ***************************************************************************************
// Copyright (c) 2023-2025 Peng Cheng Laboratory
// Copyright (c) 2023-2025 Institute of Computing Technology, Chinese Academy of Sciences
// Copyright (c) 2023-2025 Beijing Institute of Open Source Chip
//
// iEDA is licensed under Mulan PSL v2.
// You can use this software according to the terms and conditions of the Mulan PSL v2.
// You may obtain a copy of the Mulan PSL v2 at:
// http://license.coscl.org.cn/MulanPSL2
//
// THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
// EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
// See the Mulan PSL v2 for more details.
// ***************************************************************************************
#pragma once

#include "ZHHeader.hpp"

namespace izh {

class DFConfig
{
 public:
  DFConfig() = default;
  ~DFConfig() = default;
  // getter
  std::string& get_hierarchy_path() { return _hierarchy_path; }
  std::map<std::string, std::string>& get_child_master_to_def_path_map() { return _child_master_to_def_path_map; }
  std::map<std::string, std::string>& get_power_alias_to_net_name_map() { return _power_alias_to_net_name_map; }
  // setter
  void set_hierarchy_path(const std::string& hierarchy_path) { _hierarchy_path = hierarchy_path; }
  void set_child_master_to_def_path_map(const std::map<std::string, std::string>& child_master_to_def_path_map)
  {
    _child_master_to_def_path_map = child_master_to_def_path_map;
  }
  void set_power_alias_to_net_name_map(const std::map<std::string, std::string>& power_alias_to_net_name_map)
  {
    _power_alias_to_net_name_map = power_alias_to_net_name_map;
  }
  // function

 private:
  std::string _hierarchy_path;
  std::map<std::string, std::string> _child_master_to_def_path_map;
  std::map<std::string, std::string> _power_alias_to_net_name_map;
};

}  // namespace izh
