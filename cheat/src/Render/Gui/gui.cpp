#include "gui.h"
#include "global.h"
#include "imgui.h"
#include "Utils.h"
#include "utils/gui-util.hpp"

void Gui::Render()
{
	auto& vars = Vars::GetInstance();
    ImGui::Begin(xorstr("##wuwbzxczi2"), nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);
    {


		ImGui::BeginChild(xorstr("##qycsasdaum"), ImVec2(100, GuiUtil::GetY()), TRUE);
		{

#define MENU_MODULES(name, tab) ImGui::PushStyleColor(ImGuiCol_Button, m_MenuTab == (tab) ? active : inactive); \
		     ImGui::Button(name, ImVec2(90 - 10, 22)); \
		     if (ImGui::IsItemClicked()) m_MenuTab = tab; \

			MENU_MODULES(xorstr("mymethods"), 0);

#undef MENU_MODULES
		}
		ImGui::EndChild();

		GuiUtil::LineVertical();

		ImGui::BeginChild(xorstr("##uiihzxcxzgi"), ImVec2(GuiUtil::GetX(), GuiUtil::GetY()), TRUE);
		switch (m_MenuTab)
		{
		case 0: // Features
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
			ImGui::BeginGroup();

			ImGui::CheckboxFill(xorstr("uncle"), &vars.GodMode.value());

			ImGui::CheckboxFill(xorstr("dash"), &vars.KillAura.value());

			ImGui::CheckboxFill(xorstr("plus ultra"), &vars.DamageHack.value());
			if (vars.DamageHack.value())
				ImGui::SliderInt(xorstr("mynignog"), &vars.DamageHackValue.value(), 10000, 100000000, "%d");

			ImGui::EndGroup();
			break;
		}

		ImGui::EndChild();
    }

    ImGui::End();
}