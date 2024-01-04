#pragma once

UENUM(BlueprintType)
enum ESubsystemState : uint8
{
	Functional UMETA(DisplayName="Functional"),
	Unpowered UMETA(DisplayName="Unpowered"),
	Broken UMETA(DisplayName="Broken")
};
