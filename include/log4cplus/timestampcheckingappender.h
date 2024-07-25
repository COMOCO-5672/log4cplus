#pragma once

#include <log4cplus/streams.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/appender.h>

namespace log4cplus
{
    class TimestampCheckingAppender : public Appender {
    public:
        TimestampCheckingAppender();
        virtual ~TimestampCheckingAppender() override;

        virtual void close() override;

    protected:
        virtual void append(const log4cplus::spi::InternalLoggingEvent &event) override;

    private:
        void checkTimeStamp(const std::string &filename);
    };
}

