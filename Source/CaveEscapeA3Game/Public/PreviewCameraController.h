#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PreviewCameraController.generated.h"

UCLASS()
class CAVEESCAPEA3GAME_API APreviewCameraController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APreviewCameraController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		AActor* CameraStartPoint;

		AActor* CameraEndPoint;

	UPROPERTY(EditAnywhere)
		float TimeToHoldPreviewCamera;

		UPROPERTY(EditAnywhere)
		float TimeToMoveCameraToPlayer;

		float cameraWorkEndCountdownTimer;

		bool CameraMovementStarted;
		bool CameraMovementFinished;

		void ChangeCamera();
		void CameraWorkComplete();
};
