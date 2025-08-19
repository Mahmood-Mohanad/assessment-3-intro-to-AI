// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_AIController.h"
#include "NPC.h"


ANPC_AIController::ANPC_AIController(FObjectInitializer const& ObjectInitializer)
{

}

void ANPC_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (ANPC* const npc = Cast<ANPC>(InPawn))  //checking te cast 
	{
		if (UBehaviorTree* const tree = npc->GetBehaviorTree())
		{
			UBlackboardComponent* b;
			UseBlackboard(tree->BlackboardAsset, b);
			Blackboard = b;
			RunBehaviorTree(tree);
		}
	}
}