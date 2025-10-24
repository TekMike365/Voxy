#pragma once

namespace Voxy {

/*
  2 types (Core & App)
  Needs the ability to be named
  Severity: Trace, Info, Warn, Error
  Stripped on release? // piped into a file?

  format:
    [timestamp] [Core/App:Name] (Severity): msg

  usage:
    # Core
    CoreLogger logger("Renderer");
    logger.Info("logger initialized.");

    [2020-11-26 08:25:04 +00:00] [Core:Renderer] (info): logger initialized

    # App
    Logger logger("Player");
    logger.Warn("Not good");

    [2020-11-26 08:25:04 +00:00] [App:Player] (warn): Not good
 */
class Logger {
public:
private:
};

} // namespace Voxy
