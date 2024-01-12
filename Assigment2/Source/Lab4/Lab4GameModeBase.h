// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NetAvatar.h"
#include "Lab4GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class LAB4_API ALab4GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	ALab4GameModeBase();

    virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;

    UFUNCTION(BlueprintCallable)
    void AvatarsOverlapped(ANetAvatar* AvatarA, ANetAvatar* AvatarB);

    UFUNCTION(BlueprintCallable)
    void EndGame();

private:
    int TotalPlayerCount;
    int TotalGames;
    int PlayerStartIndex;

    TArray<APlayerController*> AllPlayers;

    AActor* GetPlayerStart(FString Name, int Index);

    AActor* AssignTeamAndPlayerStart(AController* Player);
};
