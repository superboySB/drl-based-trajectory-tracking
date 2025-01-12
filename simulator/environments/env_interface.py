from typing import Any
from abc import abstractmethod

from gym import Env
from gym.spaces import Space


class CustomizedEnvInterface:
    @abstractmethod
    def export_environment_data(self) -> Any:
        raise NotImplementedError


class ExtendedGymEnv(Env, CustomizedEnvInterface):
    pass
