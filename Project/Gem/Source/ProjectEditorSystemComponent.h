
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
        AZ_COMPONENT(ProjectEditorSystemComponent, "{4537A507-C93D-4225-9006-27024D3EC1F5}", BaseSystemComponent);
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
