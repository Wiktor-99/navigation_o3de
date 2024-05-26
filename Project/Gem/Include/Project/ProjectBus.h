/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Project
{
    class ProjectRequests
    {
    public:
        AZ_RTTI(ProjectRequests, "{AE44C1BB-46DB-448A-9701-A82E47667612}");
        virtual ~ProjectRequests() = default;
        // Put your public methods here
    };

    class ProjectBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using ProjectRequestBus = AZ::EBus<ProjectRequests, ProjectBusTraits>;
    using ProjectInterface = AZ::Interface<ProjectRequests>;

} // namespace Project
