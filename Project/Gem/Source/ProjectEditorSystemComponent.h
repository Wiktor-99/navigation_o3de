
#pragma once

#include <AzToolsFramework/API/ToolsApplicationAPI.h>

#include <ProjectSystemComponent.h>

namespace Project
{
    /// System component for Project editor
    class ProjectEditorSystemComponent
        : public ProjectSystemComponent
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = ProjectSystemComponent;
    public:
        AZ_COMPONENT(ProjectEditorSystemComponent, "{F6591829-934C-4E21-A84E-B906EBAB81EC}", BaseSystemComponent);
        static void Reflect(AZ::ReflectContext* context);

        ProjectEditorSystemComponent();
        ~ProjectEditorSystemComponent();

    private:
        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        // AZ::Component
        void Activate() override;
        void Deactivate() override;
    };
} // namespace Project
