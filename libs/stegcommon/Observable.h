//
// Created by Roumite on 25/02/2026.
//

#pragma once

#include <functional>
#include <vector>
#include <mutex>

class Observable {
public:
    void add_callback(std::function<void()> cb) {
        _callbacks.push_back(std::move(cb));
    }
protected:
    Observable() = default;
    Observable(const Observable&) = delete;
    Observable& operator=(const Observable&) = delete;

    void call_callbacks()
    {
        for (auto& cb : _callbacks) {
            cb();
        }
        _callbacks.clear();
    }
private:
    std::vector<std::function<void()>> _callbacks;
};