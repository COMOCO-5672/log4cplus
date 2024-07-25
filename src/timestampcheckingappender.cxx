#include <log4cplus/appender.h>
#include <log4cplus/timestampcheckingappender.h>

#include <filesystem>

namespace log4cplus
{
    TimestampCheckingAppender::TimestampCheckingAppender()
    {

    }

    TimestampCheckingAppender::~TimestampCheckingAppender()
    {

    }

    void TimestampCheckingAppender::close()
    {

    }

    void TimestampCheckingAppender::append(const log4cplus::spi::InternalLoggingEvent &event)
    {
        // Call parent class append
        Appender::append(event);

        // Check timestamp logic
        std::string filename = "";
        checkTimeStamp(filename);
    }

    void TimestampCheckingAppender::checkTimeStamp(const std::string &filename)
    {
        namespace fs = std::filesystem;
        auto now = std::chrono::system_clock::now();
        auto file_time = fs::last_write_time(filename);
        // TODO::The obtained file timestamp and the UTC timestamp
        // have differences, so they cannot be compared. 
        auto file_age =  now.time_since_epoch() - file_time.time_since_epoch();

        // Define your time limit, e.g., 3 days
        auto time_limit = std::chrono::hours(72);
        if (file_age > time_limit) {
            fs::remove(filename);
        }
    }
}
