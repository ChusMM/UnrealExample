// Fill out your copyright notice in the Description page of Project Settings.

#include "ScoreController.h"
#include "Blueprint/UserWidget.h"
#include "TextWidgetTypes.h"
#include "TextBlock.h"

// Sets default values
AScoreController::AScoreController()
{
    score = 0;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScoreController::BeginPlay()
{
	Super::BeginPlay();
    
    if (ScoreTextWidget) {
        pScoreTextWidget = CreateWidget<UUserWidget>(GetGameInstance(), ScoreTextWidget); // 1
        
        if (pScoreTextWidget.IsValid()) {
            pScoreTextWidget->AddToViewport(); // 2
            pScoreText = (UTextBlock *) pScoreTextWidget->GetWidgetFromName("ScoreText"); // 3
        }
    }
	
}

void AScoreController::IncreaseScore(int amount) {
    if (pScoreText.IsValid()) {
        score += amount;
        pScoreText->SetText(FText::FromString(FString::FromInt(score)));
    }
}

// Called every frame
void AScoreController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

