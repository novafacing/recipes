"""
Module to handle logs for the reface project.

Other modules should do something like:

```
from project.logger import logging

logger = logging.getLogger(__name__)
logger.debug("This is a debug message")
```
"""

import logging as python_logging
from typing import Any, Union


class ProjectLogger:
    """Project logging utility."""

    def __init__(self) -> None:
        """
        Set up the log format and levels for the logger.
        """
        # self.formatter = python_logging.Formatter(
        #    "%(asctime)s|%(name)s|%(levelname)s|%(message)s"
        # )
        self.logger = python_logging.getLogger("Project")
        self.logger.setLevel(python_logging.DEBUG)
        # self.stream = python_logging.StreamHandler()
        # self.stream.setLevel(python_logging.DEBUG)
        # self.stream.setFormatter(self.formatter)
        # self.logger.addHandler(self.stream)

    def getLogger(
        self, name: str
    ) -> python_logging.Logger:  # pylint: disable=invalid-name
        """
        Gets a logger for a reface sub-module

        :param name: The name of the sub-module, probably __name__
        """
        return self.logger.getChild(name)

    def setLevel(self, level: Union[int, str]) -> None:  # pylint: disable=invalid-name
        """
        Sets the logging level for the logger.

        :param level: The logging level to set.
        """
        if isinstance(level, int):
            self.logger.setLevel(level)

        elif isinstance(level, str):
            self.logger.setLevel(
                {
                    "debug": self.DEBUG,
                    "info": self.INFO,
                    "warning": self.WARNING,
                    "error": self.ERROR,
                    "critical": self.CRITICAL,
                }[level]
            )

    def __getattr__(self, name: str) -> Any:
        """
        Fallback logging getattr to python_logging

        Fallback getattr method just tries to return
        the requested thing from logging (to make logging.ERROR
        and such seamless

        :param name: The requested attribute
        """
        return getattr(python_logging, name)
