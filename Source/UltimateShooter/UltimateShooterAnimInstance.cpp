// Fill out your copyright notice in the Description page of Project Settings.


#include "UltimateShooterAnimInstance.h"

#include "ShooterCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UUltimateShooterAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	if (!ShooterCharacter)
	{
		ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
	}
	else
	{
		//Get the lateral speed of the character from velocity
		FVector Velocity { ShooterCharacter->GetVelocity() };
		Velocity.Z = 0;
		Speed = Velocity.Size();

		//Is the character in the air?
		bIsInAir = ShooterCharacter->GetCharacterMovement()->IsFalling();

		//Is the character accelerating?
		bIsAccelerating = ShooterCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0 ? true : false;
		
	}
}

void UUltimateShooterAnimInstance::NativeInitializeAnimation()
{
	ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
}
