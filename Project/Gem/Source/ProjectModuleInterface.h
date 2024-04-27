
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>
#include <ProjectSystemComponent.h>

namespace Project
{
    class ProjectModuleInterface
        : public AZ::Module
    {
    public:
        AZ_RTTI(ProjectModuleInterface, "{BDEF3123-7076-42BF-915A-1A86990FA073}", AZ::Module);
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
