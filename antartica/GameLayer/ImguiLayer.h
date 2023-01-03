
#pragma once

#include <puffin.h>

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_sdlrenderer.h"
#include <stdio.h>
#include <SDL.h>

class ImguiLayer : public puffin::Layer
{
private:
    puffin::Container *m_container;

public:
    void OnAttach() override;
    void OnDetach() override;
    void Update() override;
    void Start() override;

    ImguiLayer()
    {
        m_container = new puffin::Container(50);
    }
};

void ImguiLayer::OnAttach()
{
    GM_CORE_TRACE("Attaching IMGUI Layer");

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForSDLRenderer(puffin::Application::Get()->GetWindow()->GetWindow(), puffin::Application::Get()->GetWindow()->GetRenderer());
    ImGui_ImplSDLRenderer_Init(puffin::Application::Get()->GetWindow()->GetRenderer());
}

void ImguiLayer::OnDetach()
{
    GM_CORE_TRACE("Detaching Game Layer");

    ImGui_ImplSDLRenderer_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void ImguiLayer::Start()
{
}

void ImguiLayer::Update()
{
    ImGui_ImplSDLRenderer_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Info", &my_tool_active);

    ImGui::Text("Framerate %f", ImGui::GetIO().Framerate);

    ImGui::End();

    ImGui::Render();
    ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
}
