
#pragma once

#include <puffin.h>
#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_sdlrenderer.h"
#include <stdio.h>
#include <SDL.h>

class GameLayer : public puffin::Layer
{
public:
    void OnAttach() override;
    void OnDetach() override;
    void Update() override;
    void Start() override;
};

void GameLayer::OnAttach()
{
    /*
    // It's only in the function calm down
    using namespace puffin;

    GM_CORE_TRACE("Attaching Game Layer");

    // Make an image

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForSDLRenderer(puffin::Application::Get()->GetWindow()->GetWindow(), puffin::Application::Get()->GetWindow()->GetRenderer());
    ImGui_ImplSDLRenderer_Init(puffin::Application::Get()->GetWindow()->GetRenderer());
    */
}

void GameLayer::OnDetach()
{
    GM_CORE_TRACE("Detaching Game Layer");
}

void GameLayer::Start()
{
}

bool my_tool_active = true;

void GameLayer::Update()
{
    /*
    puffin::container->UpdateComponents();

    ImGui_ImplSDLRenderer_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Info", &my_tool_active);

    ImGui::Text("Framerate %f", ImGui::GetIO().Framerate);
    // ImGui::Image(m_view.GetTexture(), {192, 108});

    ImGui::End();

    ImGui::Render();
    ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
    */
}
