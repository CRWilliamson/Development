// Fill out your copyright notice in the Description page of Project Settings.

#include "PawnController.h"

APawnController::APawnController()
{
	bShowMouseCursor = true;
}

void APawnController::BeginPlay()
{
	EnableInput(this);
}


