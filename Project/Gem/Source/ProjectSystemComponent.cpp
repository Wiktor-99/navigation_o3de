

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "ProjectSystemComponent.h"

namespace Project
{
    void ProjectSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<ProjectSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<ProjectSystemComponent>("Project", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void ProjectSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("ProjectService"));
    }

    void ProjectSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("ProjectService"));
    }

    void ProjectSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void ProjectSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    ProjectSystemComponent::ProjectSystemComponent()
    {
        if (ProjectInterface::Get() == nullptr)
        {
            ProjectInterface::Register(this);
        }
    }

    ProjectSystemComponent::~ProjectSystemComponent()
    {
        if (ProjectInterface::Get() == this)
        {
            ProjectInterface::Unregister(this);
        }
    }

    void ProjectSystemComponent::Init()
    {
    }

    void ProjectSystemComponent::Activate()
    {
        ProjectRequestBus::Handler::BusConnect();
    }

    void ProjectSystemComponent::Deactivate()
    {
        ProjectRequestBus::Handler::BusDisconnect();
    }
}
