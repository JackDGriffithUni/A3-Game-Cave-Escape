// Pls no steal, I worked hard on it


#include "PreviewCameraController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APreviewCameraController::APreviewCameraController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true; // this will allow the camera to move to the player and unpause the game

}

// Called when the game starts or when spawned
void APreviewCameraController::BeginPlay()
{
	APlayerController* LocalPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	LocalPlayerController->SetViewTarget(CameraStartPoint);
	CameraMovementFinished = false;
	CameraMovementStarted = false;
	cameraWorkEndCountdownTimer = TimeToMoveCameraToPlayer;
	UGameplayStatics::SetGamePaused(GetWorld(), true);

	Super::BeginPlay();
	
}

void APreviewCameraController::ChangeCamera()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	AActor* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

	APlayerController* LocalPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (LocalPlayerController)
	{
		if ((LocalPlayerController->GetViewTarget() != PlayerPawn) && (PlayerPawn != nullptr))
		{
			LocalPlayerController->SetViewTarget(PlayerPawn);
		}
	}
	
}

void APreviewCameraController::CameraWorkComplete()
{

}

// Called every frame
void APreviewCameraController::Tick(float DeltaTime)
{
	if (CameraMovementFinished == false)
	{
		if (TimeToHoldPreviewCamera > 0.0f)
		{
			TimeToHoldPreviewCamera -= DeltaTime;
		}
		else if (TimeToHoldPreviewCamera <= 0.0f)
		{
			if (CameraMovementStarted == false)
			{
				CameraMovementStarted = true;
				ChangeCamera();
			}

			if (TimeToMoveCameraToPlayer > 0.0f)
			{
				TimeToMoveCameraToPlayer -= DeltaTime;
			}
			else if (TimeToMoveCameraToPlayer <= 0.0f)
			{
				CameraWorkComplete();
			}
		}
	}
	Super::Tick(DeltaTime);

}

