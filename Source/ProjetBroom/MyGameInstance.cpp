// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "Containers/UnrealString.h"
#include "Engine/DataAsset.h"
#include "Engine/ObjectLibrary.h"
#include "Engine/Texture.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"
#include "UObject/UObjectGlobals.h"

TArray<FString> UMyGameInstance::GetAllMapNamesWithPath(FString Path)
{
    auto ObjectLibrary = UObjectLibrary::CreateLibrary(UWorld::StaticClass(), false, true);
    ObjectLibrary->LoadAssetDataFromPath(Path);
    TArray<FAssetData> AssetDatas;
    ObjectLibrary->GetAssetDataList(AssetDatas);
    UE_LOG(LogTemp, Warning, TEXT("Found maps: %d"), AssetDatas.Num());

    TArray<FString> Names = TArray<FString>();

    for (int32 i = 0; i < AssetDatas.Num(); ++i)
    {
        FAssetData &AssetData = AssetDatas[i];

        auto name = AssetData.AssetName.ToString();
        Names.Add(name);
    }
    return Names;
}
TArray<UObject*> UMyGameInstance::GetAllObjectsWithPath(FString Path)
{
    auto ObjectLibrary = UObjectLibrary::CreateLibrary(UObject::StaticClass(), false, true);
    ObjectLibrary->LoadAssetDataFromPath(Path);
    TArray<FAssetData> AssetDatas;
    ObjectLibrary->GetAssetDataList(AssetDatas);
    UE_LOG(LogTemp, Warning, TEXT("Found maps: %d"), AssetDatas.Num());

    TArray<FString> Names = TArray<FString>();
    TArray<UObject*> objets;

    for (int32 i = 0; i < AssetDatas.Num(); ++i)
    {
        FAssetData &AssetData = AssetDatas[i];

        auto name = AssetData.AssetName.ToString();
        Names.Add(name);
        objets.Add(AssetData.GetAsset());

    }
    return objets;
}
