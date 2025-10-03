#pragma once

#include "CoreMinimal.h"
#include "PhysicalMaterials/PhysicalMaterial.h"

#include "%CLASS_PREFIX%PhysicsTypes.generated.h"


/**
 * @namespace F%CLASS_PREFIX%CollisionTypes
 * All custom collision types for the current project
 *
 * When adding a new collision channel, declare it like this. The epic way would just be a #define.
 * static constexpr ECollisionChannel ECC_Interaction = ECC_GameTraceChannel1;
 */
namespace F%CLASS_PREFIX%CollisionTypes
{
// Add values here
};

/**
 * @namespace F%CLASS_PREFIX%CollisionPresets
 * All custom collision presets for the current project
 *
 * When adding a new collision preset, declare it like this. The epic way would just be a #define.
 * static const FName Preset_Interaction = FName(TEXT("Interaction"));
 */
namespace F%CLASS_PREFIX%CollisionPresets
{
// Add values here
}

/**
 * @enum E%CLASS_PREFIX%PhysicalSurface
 * An enum that remaps Unreal surface types to more readable names
 */
UENUM(BlueprintType)
enum class E%CLASS_PREFIX%PhysicalSurface : uint8
{
	Default = EPhysicalSurface::SurfaceType_Default,

	// Add others like so:
	// Metal = EPhysicalSurface::SurfaceType1
};

FORCEINLINE bool operator==(const EPhysicalSurface& Surf, const E%CLASS_PREFIX%PhysicalSurface& OurSurf)
{
	return static_cast<int32>(Surf) == static_cast<int32>(OurSurf);
};

FORCEINLINE bool operator!=(const EPhysicalSurface& Surf, const E%CLASS_PREFIX%PhysicalSurface& OurSurf)
{
	return !(Surf == OurSurf);
};
