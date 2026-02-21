#include "ReplayManager.hpp"
#include <Geode/Geode.hpp>

namespace replay {
    void ReplayManager::startRecording() {
        m_recording = true;
    }

    void ReplayManager::stopRecording() {
        m_recording = false;
    }

    bool ReplayManager::isRecording() const {
        return m_recording;
    }

    void ReplayManager::saveAtt(std::string const& fileName) {
        (void)fileName;
    }

    const char* reToString(RecordEvent event) {
        switch(event) {
            case RecordEvent::Start: return "Start";
            case RecordEvent::End: return "End";
            default: return "NULL";
        }
    }

}

bool updateRecord(replay::RecordEvent type) {
    switch (type) {
        case replay::RecordEvent::Start:
            return true;
        case replay::RecordEvent::End:
            return true;
        default:
            geode::log::error("ERROR: Unknown 'RecordEvent' in function updateRecord || src/replay/core/ReplayManager.cpp");
            return false;
    }
}