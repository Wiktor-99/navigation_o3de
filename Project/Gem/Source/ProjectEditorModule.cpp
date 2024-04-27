
#include <ProjectModuleInterface.h>
#include "ProjectEditorSystemComponent.h"

#include "ProjectSampleComponent.h"
namespace Project
{
    class ProjectEditorModule
        : public ProjectModuleInterface
    {
    public:
        AZ_RTTI(ProjectEditorModule, "{8EE01C9A-53FB-4190-A4E2-55E6AF9FBE4C}", ProjectModuleInterface);
        AZ_CLASS_ALLOCATOR(ProjectEditorModule, AZ::SystemAllocator, 0);

        ProjectEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                ProjectEditorSystemComponent::CreateDescriptor(),
                ProjectSampleComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<ProjectEditorSystemComponent>(),
            };
        }
    };
}// namespace Project

AZ_DECLARE_MODULE_CLASS(Gem_Project, Project::ProjectEditorModule)
