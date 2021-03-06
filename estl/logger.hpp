#ifndef ESTL_LOGGER_HPP_
#define ESTL_LOGGER_HPP_

#include <cstdarg>
#include <ctime>
#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <memory>

namespace estl {
namespace logger {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgnu-zero-variadic-macro-arguments"

#define Default() Logger::Get()->GetLogger()
#define Fatal(msg, ...)                                                    \
  Logger::Get()->GetLogger()->_LogFatal(msg, __FILE__, __func__, __LINE__, \
                                        ##__VA_ARGS__)
#define Error(msg, ...)                                                    \
  Logger::Get()->GetLogger()->_LogError(msg, __FILE__, __func__, __LINE__, \
                                        ##__VA_ARGS__)
#define Warning(msg, ...)                                                    \
  Logger::Get()->GetLogger()->_LogWarning(msg, __FILE__, __func__, __LINE__, \
                                          ##__VA_ARGS__)
#define Success(msg, ...)                                                    \
  Logger::Get()->GetLogger()->_LogSuccess(msg, __FILE__, __func__, __LINE__, \
                                          ##__VA_ARGS__)
#define Debug(msg, ...)                                                    \
  Logger::Get()->GetLogger()->_LogDebug(msg, __FILE__, __func__, __LINE__, \
                                        ##__VA_ARGS__)
#define Trace(msg, ...)                                                    \
  Logger::Get()->GetLogger()->_LogTrace(msg, __FILE__, __func__, __LINE__, \
                                        ##__VA_ARGS__)
#define Info(msg, ...)                                                    \
  Logger::Get()->GetLogger()->_LogInfo(msg, __FILE__, __func__, __LINE__, \
                                       ##__VA_ARGS__)
#define Version(msg, ...)                                                    \
  Logger::Get()->GetLogger()->_LogVersion(msg, __FILE__, __func__, __LINE__, \
                                          ##__VA_ARGS__)

#define Log(type, msg, ...) \
  _Log(type, msg, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define LogFatal(msg, ...) \
  _LogFatal(msg, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define LogError(msg, ...) \
  _LogError(msg, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define LogWarning(msg, ...) \
  _LogWarning(msg, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define LogSuccess(msg, ...) \
  _LogSuccess(msg, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define LogDebug(msg, ...) \
  _LogDebug(msg, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define LogTrace(msg, ...) \
  _LogTrace(msg, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define LogInfo(msg, ...) \
  _LogInfo(msg, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define LogVersion(msg, ...) \
  _LogVersion(msg, __FILE__, __func__, __LINE__, ##__VA_ARGS__)

#define ConsoleLog(type, msg, ...)                                    \
  ConsoleLogger::Get()->_Log(type, msg, __FILE__, __func__, __LINE__, \
                             ##__VA_ARGS__)
#define ConsoleLogFatal(msg, ...)                                    \
  ConsoleLogger::Get()->_LogFatal(msg, __FILE__, __func__, __LINE__, \
                                  ##__VA_ARGS__)
#define ConsoleLogError(msg, ...)                                    \
  ConsoleLogger::Get()->_LogError(msg, __FILE__, __func__, __LINE__, \
                                  ##__VA_ARGS__)
#define ConsoleLogWarning(msg, ...)                                    \
  ConsoleLogger::Get()->_LogWarning(msg, __FILE__, __func__, __LINE__, \
                                    ##__VA_ARGS__)
#define ConsoleLogSuccess(msg, ...)                                    \
  ConsoleLogger::Get()->_LogSuccess(msg, __FILE__, __func__, __LINE__, \
                                    ##__VA_ARGS__)
#define ConsoleLogDebug(msg, ...)                                    \
  ConsoleLogger::Get()->_LogDebug(msg, __FILE__, __func__, __LINE__, \
                                  ##__VA_ARGS__)
#define ConsoleLogTrace(msg, ...)                                    \
  ConsoleLogger::Get()->_LogTrace(msg, __FILE__, __func__, __LINE__, \
                                  ##__VA_ARGS__)
#define ConsoleLogInfo(msg, ...)                                    \
  ConsoleLogger::Get()->_LogInfo(msg, __FILE__, __func__, __LINE__, \
                                 ##__VA_ARGS__)
#define ConsoleLogVersion(msg, ...)                                    \
  ConsoleLogger::Get()->_LogVersion(msg, __FILE__, __func__, __LINE__, \
                                    ##__VA_ARGS__)

#define FileLog(type, msg, ...)                                    \
  FileLogger::Get()->_Log(type, msg, __FILE__, __func__, __LINE__, \
                          ##__VA_ARGS__)
#define FileLogFatal(msg, ...) \
  FileLogger::Get()->_LogFatal(msg, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define FileLogError(msg, ...) \
  FileLogger::Get()->_LogError(msg, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define FileLogWarning(msg, ...)                                    \
  FileLogger::Get()->_LogWarning(msg, __FILE__, __func__, __LINE__, \
                                 ##__VA_ARGS__)
#define FileLogSuccess(msg, ...)                                    \
  FileLogger::Get()->_LogSuccess(msg, __FILE__, __func__, __LINE__, \
                                 ##__VA_ARGS__)
#define FileLogDebug(msg, ...) \
  FileLogger::Get()->_LogDebug(msg, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define FileLogTrace(msg, ...) \
  FileLogger::Get()->_LogTrace(msg, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define FileLogInfo(msg, ...) \
  FileLogger::Get()->_LogInfo(msg, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define FileLogVersion(msg, ...)                                    \
  FileLogger::Get()->_LogVersion(msg, __FILE__, __func__, __LINE__, \
                                 ##__VA_ARGS__)

#define DailyLog(type, msg, ...)                                    \
  DailyLogger::Get()->_Log(type, msg, __FILE__, __func__, __LINE__, \
                           ##__VA_ARGS__)
#define DailyLogFatal(msg, ...)                                    \
  DailyLogger::Get()->_LogFatal(msg, __FILE__, __func__, __LINE__, \
                                ##__VA_ARGS__)
#define DailyLogError(msg, ...)                                    \
  DailyLogger::Get()->_LogError(msg, __FILE__, __func__, __LINE__, \
                                ##__VA_ARGS__)
#define DailyLogWarning(msg, ...)                                    \
  DailyLogger::Get()->_LogWarning(msg, __FILE__, __func__, __LINE__, \
                                  ##__VA_ARGS__)
#define DailyLogSuccess(msg, ...)                                    \
  DailyLogger::Get()->_LogSuccess(msg, __FILE__, __func__, __LINE__, \
                                  ##__VA_ARGS__)
#define DailyLogDebug(msg, ...)                                    \
  DailyLogger::Get()->_LogDebug(msg, __FILE__, __func__, __LINE__, \
                                ##__VA_ARGS__)
#define DailyLogTrace(msg, ...)                                    \
  DailyLogger::Get()->_LogTrace(msg, __FILE__, __func__, __LINE__, \
                                ##__VA_ARGS__)
#define DailyLogInfo(msg, ...) \
  DailyLogger::Get()->_LogInfo(msg, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define DailyLogVersion(msg, ...)                                    \
  DailyLogger::Get()->_LogVersion(msg, __FILE__, __func__, __LINE__, \
                                  ##__VA_ARGS__)

#define CounterLog(type, msg, ...)                                    \
  CounterLogger::Get()->_Log(type, msg, __FILE__, __func__, __LINE__, \
                             ##__VA_ARGS__)
#define CounterLogFatal(msg, ...)                                    \
  CounterLogger::Get()->_LogFatal(msg, __FILE__, __func__, __LINE__, \
                                  ##__VA_ARGS__)
#define CounterLogError(msg, ...)                                    \
  CounterLogger::Get()->_LogError(msg, __FILE__, __func__, __LINE__, \
                                  ##__VA_ARGS__)
#define CounterLogWarning(msg, ...)                                    \
  CounterLogger::Get()->_LogWarning(msg, __FILE__, __func__, __LINE__, \
                                    ##__VA_ARGS__)
#define CounterLogSuccess(msg, ...)                                    \
  CounterLogger::Get()->_LogSuccess(msg, __FILE__, __func__, __LINE__, \
                                    ##__VA_ARGS__)
#define CounterLogDebug(msg, ...)                                    \
  CounterLogger::Get()->_LogDebug(msg, __FILE__, __func__, __LINE__, \
                                  ##__VA_ARGS__)
#define CounterLogTrace(msg, ...)                                    \
  CounterLogger::Get()->_LogTrace(msg, __FILE__, __func__, __LINE__, \
                                  ##__VA_ARGS__)
#define CounterLogInfo(msg, ...)                                    \
  CounterLogger::Get()->_LogInfo(msg, __FILE__, __func__, __LINE__, \
                                 ##__VA_ARGS__)
#define CounterLogVersion(msg, ...)                                    \
  CounterLogger::Get()->_LogVersion(msg, __FILE__, __func__, __LINE__, \
                                    ##__VA_ARGS__)

#define StreamLog(type, msg, ...)                                    \
  StreamLogger::Get()->_Log(type, msg, __FILE__, __func__, __LINE__, \
                            ##__VA_ARGS__)
#define StreamLogFatal(msg, ...)                                    \
  StreamLogger::Get()->_LogFatal(msg, __FILE__, __func__, __LINE__, \
                                 ##__VA_ARGS__)
#define StreamLogError(msg, ...)                                    \
  StreamLogger::Get()->_LogError(msg, __FILE__, __func__, __LINE__, \
                                 ##__VA_ARGS__)
#define StreamLogWarning(msg, ...)                                    \
  StreamLogger::Get()->_LogWarning(msg, __FILE__, __func__, __LINE__, \
                                   ##__VA_ARGS__)
#define StreamLogSuccess(msg, ...)                                    \
  StreamLogger::Get()->_LogSuccess(msg, __FILE__, __func__, __LINE__, \
                                   ##__VA_ARGS__)
#define StreamLogDebug(msg, ...)                                    \
  StreamLogger::Get()->_LogDebug(msg, __FILE__, __func__, __LINE__, \
                                 ##__VA_ARGS__)
#define StreamLogTrace(msg, ...)                                    \
  StreamLogger::Get()->_LogTrace(msg, __FILE__, __func__, __LINE__, \
                                 ##__VA_ARGS__)
#define StreamLogInfo(msg, ...)                                    \
  StreamLogger::Get()->_LogInfo(msg, __FILE__, __func__, __LINE__, \
                                ##__VA_ARGS__)
#define StreamLogVersion(msg, ...)                                    \
  StreamLogger::Get()->_LogVersion(msg, __FILE__, __func__, __LINE__, \
                                   ##__VA_ARGS__)
#pragma clang diagnostic pop

  enum LogType {
    FATAL = 0,
    ERROR = 1,
    WARNING = 2,
    SUCCESS = 3,
    DEBUG = 4,
    TRACE = 5,
    INFO = 6,
    VERSION = 7
  };

  class LoggerBase {
   public:
    LoggerBase() {}
    virtual ~LoggerBase() {}

    void _Log(LogType type, std::string_view message, std::string_view file,
              std::string_view func, unsigned int line, va_list args) {
      char fmt[255];
      std::time_t raw_time;
      std::time(&raw_time);
      std::tm* current_tm = std::localtime(&raw_time);
      vsnprintf(fmt, 255, message.data(), args);
      std::string body_str(fmt);
      std::string type_str = TypeString(type);
      std::string fmt_str = log_fmt_[type];
      std::string line_str = std::to_string(line);
      std::strftime(fmt, 255, time_fmt_[0].c_str(), current_tm);
      std::string date_str(fmt);
      std::strftime(fmt, 255, time_fmt_[1].c_str(), current_tm);
      std::string time_str(fmt);
      std::strftime(fmt, 255, time_fmt_[2].c_str(), current_tm);
      std::string date_time_str(fmt);
      ReplaceSubString(fmt_str, "__TYPE__", type_str);
      ReplaceSubString(fmt_str, "__FILE__", file);
      ReplaceSubString(fmt_str, "__FUNC__", func);
      ReplaceSubString(fmt_str, "__LINE__", line_str);
      ReplaceSubString(fmt_str, "__BODY__", body_str);
      ReplaceSubString(fmt_str, "__DATE__", date_str);
      ReplaceSubString(fmt_str, "__TIME__", time_str);
      ReplaceSubString(fmt_str, "__DATE_TIME__", date_time_str);
      HandleLog(type, fmt_str);
    }

    void _LogFatal(std::string_view message, std::string_view file,
                   std::string_view func, unsigned int line, ...) {
      va_list args;
      va_start(args, line);
      _Log(FATAL, message, file, func, line, args);
      va_end(args);
    }
    void _LogError(std::string_view message, std::string_view file,
                   std::string_view func, unsigned int line, ...) {
      va_list args;
      va_start(args, line);
      _Log(ERROR, message, file, func, line, args);
      va_end(args);
    }
    void _LogWarning(std::string_view message, std::string_view file,
                     std::string_view func, unsigned int line, ...) {
      va_list args;
      va_start(args, line);
      _Log(WARNING, message, file, func, line, args);
      va_end(args);
    }
    void _LogSuccess(std::string_view message, std::string_view file,
                     std::string_view func, unsigned int line, ...) {
      va_list args;
      va_start(args, line);
      _Log(SUCCESS, message, file, func, line, args);
      va_end(args);
    }
    void _LogDebug(std::string_view message, std::string_view file,
                   std::string_view func, unsigned int line, ...) {
      va_list args;
      va_start(args, line);
      _Log(DEBUG, message, file, func, line, args);
      va_end(args);
    }
    void _LogTrace(std::string_view message, std::string_view file,
                   std::string_view func, unsigned int line, ...) {
      va_list args;
      va_start(args, line);
      _Log(TRACE, message, file, func, line, args);
      va_end(args);
    }
    void _LogInfo(std::string_view message, std::string_view file,
                  std::string_view func, unsigned int line, ...) {
      va_list args;
      va_start(args, line);
      _Log(INFO, message, file, func, line, args);
      va_end(args);
    }
    void _LogVersion(std::string_view message, std::string_view file,
                     std::string_view func, unsigned int line, ...) {
      va_list args;
      va_start(args, line);
      _Log(VERSION, message, file, func, line, args);
      va_end(args);
    }

    void FormatAll(std::string fmt) {
      for (std::size_t i = 0; i < 8; i++) {
        log_fmt_[i] = fmt;
      }
    }

    void Format(LogType type, std::string fmt) { log_fmt_[type] = fmt; }

    void FormatFatal(std::string fmt) { log_fmt_[FATAL] = fmt; }
    void FormatError(std::string fmt) { log_fmt_[ERROR] = fmt; }
    void FormatWarning(std::string fmt) { log_fmt_[WARNING] = fmt; }
    void FormatSuccess(std::string fmt) { log_fmt_[SUCCESS] = fmt; }
    void FormatDebug(std::string fmt) { log_fmt_[DEBUG] = fmt; }
    void FormatTrace(std::string fmt) { log_fmt_[TRACE] = fmt; }
    void FormatInfo(std::string fmt) { log_fmt_[INFO] = fmt; }
    void FormatVersion(std::string fmt) { log_fmt_[VERSION] = fmt; }

   protected:
    std::array<std::string, 3> time_fmt_ = {
        {"%Y-%m-%d", "%H:%M:%S", "%Y-%m-%d %H:%M:%S"}};

    std::array<std::string, 8> log_fmt_ = {
        {"[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) __BODY__",
         "[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) __BODY__",
         "[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) __BODY__",
         "[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) __BODY__",
         "[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) __BODY__",
         "[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) __BODY__",
         "[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) __BODY__",
         "[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) __BODY__"}};

   private:
    virtual void HandleLog(LogType, std::string) {}
    std::string& ReplaceSubString(std::string& src, std::string pat,
                                  std::string_view rep) {
      std::size_t index = 0;
      while (true) {
        index = src.find(pat);
        if (index == std::string::npos) break;
        src.replace(index, pat.size(), rep);
      }
      return src;
    }

    std::string TypeString(LogType type) {
      switch (type) {
        case FATAL:
          return "FATAL  ";
        case ERROR:
          return "ERROR  ";
        case WARNING:
          return "WARNING";
        case SUCCESS:
          return "SUCCESS";
        case DEBUG:
          return "DEBUG  ";
        case TRACE:
          return "TRACE  ";
        case INFO:
          return "INFO   ";
        case VERSION:
          return "VESION ";
      };
    }
  };

  class ConsoleLogger : public LoggerBase {
   public:
    ConsoleLogger() : LoggerBase() { SetColor(true); }
    virtual ~ConsoleLogger() {}

    inline static ConsoleLogger* Get() {
      static ConsoleLogger instance;
      return &instance;
    }

    void SetColor(bool setting) {
      color_ = setting;
      if (setting) {
        this->log_fmt_ = {
            {"\033[1;31m[__TYPE__] <__DATE_TIME__> "
             "(__FILE__:__FUNC__:__LINE__) __BODY__\033[0m",
             "\033[31m[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) "
             "__BODY__\033[0m",
             "\033[33m[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) "
             "__BODY__\033[0m",
             "\033[32m[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) "
             "__BODY__\033[0m",
             "\033[34m[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) "
             "__BODY__\033[0m",
             "\033[35m[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) "
             "__BODY__\033[0m",
             "\033[97m[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) "
             "__BODY__\033[0m",
             "\033[1;33m[__TYPE__] <__DATE_TIME__> "
             "(__FILE__:__FUNC__:__LINE__) __BODY__\033[0m"}};
      } else {
        this->log_fmt_ = {
            {"[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) __BODY__",
             "[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) __BODY__",
             "[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) __BODY__",
             "[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) __BODY__",
             "[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) __BODY__",
             "[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) __BODY__",
             "[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) __BODY__",
             "[__TYPE__] <__DATE_TIME__> (__FILE__:__FUNC__:__LINE__) "
             "__BODY__"}};
      }
    }

   private:
    virtual void HandleLog(LogType, std::string log_msg) {
      printf("%s\n", log_msg.c_str());
    }
    bool color_ = true;
  };

  class FileLogger : public LoggerBase {
   public:
    FileLogger() : LoggerBase() {}
    FileLogger(std::string file) : LoggerBase(), file_path_(file) {}
    virtual ~FileLogger() {
      if (file_.is_open()) {
        file_.close();
      }
    }

    inline static FileLogger* Get() {
      static FileLogger instance;
      return &instance;
    }

    void Open(std::string file) {
      Close();
      file_path_ = file;
    }
    void Close() {
      if (file_.is_open()) {
        file_.close();
      }
    }

    void SetFlushLevel(LogType type) { flush_level_ = type; }
    void Flush() {
      if (file_.is_open()) {
        file_.flush();
      }
    }

   private:
    virtual void HandleLog(LogType type, std::string log_msg) {
      if (file_.is_open()) {
        file_ << log_msg << std::endl;
        if (type <= flush_level_) {
          file_.flush();
        }
      } else {
        file_.open(file_path_.data());
        if (file_.is_open()) {
          file_ << log_msg << std::endl;
          if (type <= flush_level_) {
            file_.flush();
          }
        }
      }
    }

    std::ofstream file_;
    std::string file_path_;
    LogType flush_level_ = WARNING;
  };

  class DailyLogger : public FileLogger {
   public:
    DailyLogger() : FileLogger() {
      char fmt[255];
      std::time_t raw_time;
      std::time(&raw_time);
      std::tm* current_tm = std::localtime(&raw_time);
      std::strftime(fmt, 255, time_fmt_[0].c_str(), current_tm);
      std::string date_str(fmt);
      this->Open(date_str + ".log");
    }
    DailyLogger(std::string path) : FileLogger() {
      char fmt[255];
      std::time_t raw_time;
      std::time(&raw_time);
      std::tm* current_tm = std::localtime(&raw_time);
      std::strftime(fmt, 255, time_fmt_[0].c_str(), current_tm);
      std::string date_str(fmt);
      if (path.back() == '/') {
        this->Open(path + date_str + ".log");
      } else {
        this->Open(path + '/' + date_str + ".log");
      }
    }

    inline static DailyLogger* Get() {
      static DailyLogger instance;
      return &instance;
    }

    void SetPath(std::string path) {
      this->Close();
      char fmt[255];
      std::time_t raw_time;
      std::time(&raw_time);
      std::tm* current_tm = std::localtime(&raw_time);
      std::strftime(fmt, 255, time_fmt_[0].c_str(), current_tm);
      std::string date_str(fmt);
      if (path.back() == '/') {
        this->Open(path + date_str + ".log");
      } else {
        this->Open(path + '/' + date_str + ".log");
      }
    }
  };

  class CounterLogger : public FileLogger {
   public:
    CounterLogger() : FileLogger() {
      char fmt[255];
      std::time_t raw_time;
      std::time(&raw_time);
      std::tm* current_tm = std::localtime(&raw_time);
      std::strftime(fmt, 255, time_fmt_[0].c_str(), current_tm);
      std::string date_str(fmt);
      std::size_t count = FileCounter(date_str);
      if (count != 0) {
        this->Open(date_str + "_" + std::to_string(count) + ".log");
      } else {
        this->Open(date_str + ".log");
      }
    }
    CounterLogger(std::string path) : FileLogger() {
      char fmt[255];
      std::time_t raw_time;
      std::time(&raw_time);
      std::tm* current_tm = std::localtime(&raw_time);
      std::strftime(fmt, 255, time_fmt_[0].c_str(), current_tm);
      std::string date_str(fmt);
      std::size_t count = 0;
      if (path.back() == '/') {
        count = FileCounter(path + date_str);
      } else {
        count = FileCounter(path);
      }
      if (count != 0) {
        if (path.back() == '/') {
          this->Open(path + date_str + "_" + std::to_string(count) + ".log");
        } else {
          this->Open(path + "_" + std::to_string(count) + ".log");
        }
      } else {
        if (path.back() == '/') {
          this->Open(path + date_str + ".log");
        } else {
          this->Open(path + ".log");
        }
      }
    }

    inline static CounterLogger* Get() {
      static CounterLogger instance;
      return &instance;
    }

    void SetPath(std::string path) {
      char fmt[255];
      std::time_t raw_time;
      std::time(&raw_time);
      std::tm* current_tm = std::localtime(&raw_time);
      std::strftime(fmt, 255, time_fmt_[0].c_str(), current_tm);
      std::string date_str(fmt);
      std::size_t count = 0;
      if (path.back() == '/') {
        count = FileCounter(path + date_str);
      } else {
        count = FileCounter(path);
      }
      if (count != 0) {
        if (path.back() == '/') {
          this->Open(path + date_str + "_" + std::to_string(count) + ".log");
        } else {
          this->Open(path + "_" + std::to_string(count) + ".log");
        }
      } else {
        if (path.back() == '/') {
          this->Open(path + date_str + ".log");
        } else {
          this->Open(path + ".log");
        }
      }
    }

   private:
    unsigned int FileCounter(std::string path) {
      unsigned int counter = 0;
      std::ifstream f((path + ".log").c_str());
      path += "_0";
      while (f.good()) {
        f.close();
        counter++;
        path.replace(path.find_last_of('_') + 1, counter,
                     std::to_string(counter));
        f.open((path + ".log").c_str());
      }
      return counter;
    }
  };

  class StreamLogger : public LoggerBase {
   public:
    StreamLogger() : LoggerBase(), stream_(nullptr) {}
    StreamLogger(std::ostream* out) : LoggerBase(), stream_(out) {}
    virtual ~StreamLogger() {}

    inline static StreamLogger* Get() {
      static StreamLogger instance;
      return &instance;
    }

    void SetStream(std::ostream* out) { stream_ = out; }

    void SetFlushLevel(LogType type) { flush_level_ = type; }
    void Flush() {
      if (stream_ != nullptr) {
        *stream_ << std::flush;
      }
    }

   private:
    virtual void HandleLog(LogType type, std::string log_msg) {
      if (stream_ != nullptr) {
        *stream_ << log_msg << std::endl;
        if (type <= flush_level_) {
          *stream_ << std::flush;
        }
      }
    }

    LogType flush_level_;
    std::ostream* stream_;
  };

  class Logger {
   public:
    enum LoggerType { CONSOLE = 0, DAILY = 1, COUNTER = 2, STREAM = 3 };
    Logger() {}
    virtual ~Logger() {}

    inline static Logger* Get() {
      static Logger instance;
      return &instance;
    }
    inline LoggerBase* GetLogger() {
      switch (type_) {
        case CONSOLE:
          return ConsoleLogger::Get();
        case DAILY:
          return DailyLogger::Get();
        case COUNTER:
          return CounterLogger::Get();
        case STREAM:
          return StreamLogger::Get();
      }
    }

    void SetDefault(LoggerType type) { type_ = type; }

   private:
    LoggerType type_ = CONSOLE;
  };

}  // namespace logger
}  // namespace estl

#endif  // ESTL_LOGGER_HPP_
