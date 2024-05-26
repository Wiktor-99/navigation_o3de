
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
        AZ_RTTI(ProjectModule, "{FF6851B2-D84E-4A10-8D88-DCDE04C39F7D}", AZ::Module);
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
