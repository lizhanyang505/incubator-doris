// Copyright (c) 2017, Baidu.com, Inc. All Rights Reserved

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#pragma once

namespace palo {

// Because __int128 in memory is not aligned, but GCC7 will generate SSE instruction
// for __int128 load/store. This will cause segment fault.
struct PackedInt128 {
    PackedInt128& operator=(const __int128& value_) {
        value = value_;
        return *this;
    }
    PackedInt128& operator=(const PackedInt128& rhs) {
        value = rhs.value;
        return *this;
    }
    __int128 value;
} __attribute__((packed));

}