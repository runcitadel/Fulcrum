//
// FulcrumX - A fast & nimble SPV Server for Bitcoin
// Copyright (C) 2019-2022 Calin A. Culianu <calin.culianu@gmail.com>
// Copyright (C) 2022 Aaron Dewes <aaron.dewes@protonmail.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program (see LICENSE.txt).  If not, see
// <https://www.gnu.org/licenses/>.
//
#include "SubStatus.h"
#include "Util.h"

QVariant SubStatus::toVariant() const
{
    QVariant ret; // if empty we simply notify as 'null'
    if (has_value()) {
        if (auto *ba = byteArray(); ba && !ba->isEmpty())
            ret = Util::ToHexFast(*ba);
        else if (auto *bh = blockHeight(); bh && *bh)
            ret = **bh; // ptr -> optional -> value
    }
    return ret;
}
