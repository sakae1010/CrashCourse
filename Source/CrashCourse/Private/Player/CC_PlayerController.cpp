// Copyright sakae


#include "Player/CC_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"

void ACC_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (!IsValid(InputSubsystem)) return;
		
	for (UInputMappingContext* Context : InputMappingContexts)
	{
		InputSubsystem->AddMappingContext(Context,0);
	}

	UEnhancedInputComponent* EnhanceInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (!IsValid(EnhanceInputComponent)) return;
	
	EnhanceInputComponent->BindAction(JumpAction, ETriggerEvent::Started , this , &ThisClass::Jump );
	EnhanceInputComponent->BindAction(JumpAction, ETriggerEvent::Completed , this , &ThisClass::StopJumping );
	EnhanceInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered , this , &ThisClass::Move );
	EnhanceInputComponent->BindAction(LookAction, ETriggerEvent::Triggered ,this , &ThisClass::Look );
	
}

void ACC_PlayerController::Jump()
{
	if (!IsValid(GetCharacter())) return;
	
	GetCharacter()->Jump();
}

void ACC_PlayerController::StopJumping()
{
	if (!IsValid(GetCharacter())) return;
	
	GetCharacter()->StopJumping();
}

void ACC_PlayerController::Move(const FInputActionValue& Value)
{
	if (!IsValid(GetPawn())) return;
	
	const FVector2D MovementVector = Value.Get<FVector2D>();
	// Find which way is Forward)
	
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	//UE 設計上 X是往前後 / Y 是左右
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	//按鍵 / 搖桿 Y 是前後 , X 是 左右
	GetPawn()->AddMovementInput(ForwardDirection, MovementVector.Y);
	GetPawn()->AddMovementInput(RightDirection, MovementVector.X);
	
}

void ACC_PlayerController::Look(const FInputActionValue& Value)
{
	if (!IsValid(GetPawn())) return;
	
	const FVector2D LookVector = Value.Get<FVector2D>();
	AddYawInput(LookVector.X);
	AddPitchInput(LookVector.Y);
}
