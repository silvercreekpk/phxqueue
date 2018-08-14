/*
Tencent is pleased to support the open source community by making PhxQueue available.
Copyright (C) 2017 THL A29 Limited, a Tencent company. All rights reserved.
Licensed under the BSD 3-Clause License (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

<https://opensource.org/licenses/BSD-3-Clause>

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.
*/



/*phxrpc_lock_dispatcher.h

 Generated by phxrpc_pb2service from lock.proto

 Please DO NOT edit unless you know exactly what you are doing.

*/

#include "phxrpc_lock_dispatcher.h"

#include <errno.h>

#include "phxrpc/file.h"
#include "phxrpc/http.h"

#include "lock.pb.h"
#include "phxrpc_lock_service.h"


LockDispatcher::LockDispatcher(LockService &service, phxrpc::DispatcherArgs_t *dispatcher_args)
        : service_(service), dispatcher_args_(dispatcher_args) {}

LockDispatcher::~LockDispatcher() {}

const phxrpc::BaseDispatcher<LockDispatcher>::URIFuncMap &
LockDispatcher::GetURIFuncMap() {
    static phxrpc::BaseDispatcher<LockDispatcher>::URIFuncMap uri_func_map = {
        {"/phxqueue_phxrpc.lock/PhxEcho", &LockDispatcher::PhxEcho},
        {"/phxqueue_phxrpc.lock/GetLockInfo", &LockDispatcher::GetLockInfo},
        {"/phxqueue_phxrpc.lock/AcquireLock", &LockDispatcher::AcquireLock}};
    return uri_func_map;
}

int LockDispatcher::PhxEcho(const phxrpc::BaseRequest &req,
                            phxrpc::BaseResponse *const resp) {
    dispatcher_args_->server_monitor->SvrCall(-1, "PhxEcho", 1);

    int ret{-1};

    google::protobuf::StringValue req_pb;
    google::protobuf::StringValue resp_pb;

    // unpack request
    {
        ret = req.ToPb(&req_pb);
        if (0 != ret) {
            phxrpc::log(LOG_ERR, "ToPb err %d", ret);

            return -EINVAL;
        }
    }

    // logic process
    {
        if (0 == ret) ret = service_.PhxEcho(req_pb, &resp_pb);
    }

    // pack response
    {
        if (0 != resp->FromPb(resp_pb)) {
            phxrpc::log(LOG_ERR, "FromPb err %d", ret);

            return -ENOMEM;
        }
    }

    phxrpc::log(LOG_DEBUG, "RETN: PhxEcho = %d", ret);

    return ret;
}

int LockDispatcher::GetLockInfo(const phxrpc::BaseRequest &req,
                                phxrpc::BaseResponse *const resp) {
    dispatcher_args_->server_monitor->SvrCall(1, "GetLockInfo", 1);

    int ret{-1};

    phxqueue::comm::proto::GetLockInfoRequest req_pb;
    phxqueue::comm::proto::GetLockInfoResponse resp_pb;

    // unpack request
    {
        ret = req.ToPb(&req_pb);
        if (0 != ret) {
            phxrpc::log(LOG_ERR, "ToPb err %d", ret);

            return -EINVAL;
        }
    }

    // logic process
    {
        if (0 == ret) ret = service_.GetLockInfo(req_pb, &resp_pb);
    }

    // pack response
    {
        if (0 != resp->FromPb(resp_pb)) {
            phxrpc::log(LOG_ERR, "FromPb err %d", ret);

            return -ENOMEM;
        }
    }

    phxrpc::log(LOG_DEBUG, "RETN: GetLockInfo = %d", ret);

    return ret;
}

int LockDispatcher::AcquireLock(const phxrpc::BaseRequest &req,
                                phxrpc::BaseResponse *const resp) {
    dispatcher_args_->server_monitor->SvrCall(2, "AcquireLock", 1);

    int ret{-1};

    phxqueue::comm::proto::AcquireLockRequest req_pb;
    phxqueue::comm::proto::AcquireLockResponse resp_pb;

    // unpack request
    {
        ret = req.ToPb(&req_pb);
        if (0 != ret) {
            phxrpc::log(LOG_ERR, "ToPb err %d", ret);

            return -EINVAL;
        }
    }

    // logic process
    {
        if (0 == ret) ret = service_.AcquireLock(req_pb, &resp_pb);
    }

    // pack response
    {
        if (0 != resp->FromPb(resp_pb)) {
            phxrpc::log(LOG_ERR, "FromPb err %d", ret);

            return -ENOMEM;
        }
    }

    phxrpc::log(LOG_DEBUG, "RETN: AcquireLock = %d", ret);

    return ret;
}

