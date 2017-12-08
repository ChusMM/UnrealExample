// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScoreController.generated.h"

UCLASS()
class YOURFIRSTPROJECT_API AScoreController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScoreController();
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
    TSubclassOf<class UUserWidget> ScoreTextWidget;
    
    TWeakObjectPtr<class UUserWidget> pScoreTextWidget;
    
    TWeakObjectPtr<class UTextBlock> pScoreText;
    
    UFUNCTION(BlueprintCallable, Category = "Score")
    void IncreaseScore(int amount);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
private:
    int score;
    
};
