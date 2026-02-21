#pragma once

#include <string>

namespace replay {
    // dont change order or it will break

    // unless you want to make it more stable or whatever chatgpt said
    enum class RecordEvent {
        Start,
        End
    };
    const char* reToString(RecordEvent);

    class ReplayManager {
        public:
            void startRecording();
            void stopRecording();
            bool isRecording() const;

            void saveAtt(std::string const& fileName);
        private:
            bool m_recording = false;
    };
}