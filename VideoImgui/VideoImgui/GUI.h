#pragma once
#include "Imgui.h"
#include "TextEditor.h"
#include <vector>

std::vector <int> DragList;

TextEditor* te;

void DrawGUI()
{
	ImGui::Begin(u8"×÷˜IÓÃ");

	for (size_t i = 0; i < 5; i++)
	{
		ImGui::Button(std::to_string(i).c_str());
		if (i+1 < 5)
		{
			ImGui::SameLine();
		}

		if (ImGui::BeginDragDropSource())
		{
			ImGui::Text(std::string("Drag : ").append(std::to_string(i)).c_str());

			ImGui::SetDragDropPayload("DragIndexButton", &i, sizeof(int));
			ImGui::EndDragDropSource();
		}
	}

	ImGui::End();


	ImGui::Begin("Drag Window");

	ImGui::Text("Drag Target");

	if (ImGui::BeginDragDropTarget())
	{
		if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("DragIndexButton"))
		{
			DragList.push_back(*(const int*)payload->Data);
		}
		ImGui::EndDragDropTarget();
	}


	for (size_t i = 0; i < DragList.size(); i++)
	{
		if (ImGui::Button(std::to_string(DragList.at(i)).c_str()))
		{
			DragList.erase(DragList.begin() + i);
		}
		if (i + 1 < DragList.size())
		{
			ImGui::SameLine();
		}
	}

	ImGui::End();


	ImGui::Begin("TextEditor");
	te->Render("TextED");
	ImGui::End();

}