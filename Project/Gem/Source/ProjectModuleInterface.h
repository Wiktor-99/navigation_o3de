
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>
#include <ProjectSystemComponent.h>

namespace Project
{
    class ProjectModuleInterface
        : public AZ::Module
    {
    public:
        AZ_RTTI(ProjectModuleInterface, "{35CD8846-A42C-4DA0-BE75-17D4710B20CA}", AZ::Module);
        AZ_CLASS_ALLOCATOR(ProjectModuleInterface, AZ::SystemAllocator, 0);

        ProjectModuleInterface()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                ProjectSystemComponent::CreateDescriptor(),
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
