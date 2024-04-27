
#include <AzCore/Serialization/SerializeContext.h>
#include "ProjectEditorSystemComponent.h"

namespace Project
{
    void ProjectEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<ProjectEditorSystemComponent, ProjectSystemComponent>()
                ->Version(0);
        }
    }

    ProjectEditorSystemComponent::ProjectEditorSystemComponent() = default;

    ProjectEditorSystemComponent::~ProjectEditorSystemComponent() = default;

    void ProjectEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("ProjectEditorService"));
    }

    void ProjectEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("ProjectEditorService"));
    }

    void ProjectEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void ProjectEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void ProjectEditorSystemComponent::Activate()
    {
        ProjectSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void ProjectEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        ProjectSystemComponent::Deactivate();
    }

} // namespace Project
