
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "ProjectSystemComponent.h"
#include "ProjectSampleComponent.h"

namespace Project
{
    class ProjectModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(ProjectModule, "{8EE01C9A-53FB-4190-A4E2-55E6AF9FBE4C}", AZ::Module);
        AZ_CLASS_ALLOCATOR(ProjectModule, AZ::SystemAllocator);

        ProjectModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                ProjectSystemComponent::CreateDescriptor(),
                ProjectSampleComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<ProjectSystemComponent>(),
            };
        }
    };
}// namespace Project

AZ_DECLARE_MODULE_CLASS(Gem_Project, Project::ProjectModule)
