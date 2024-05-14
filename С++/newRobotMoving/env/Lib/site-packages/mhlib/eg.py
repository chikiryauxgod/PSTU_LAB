""" Example of an internal module."""

import time
from mhlib.l2 import l2


EG_VAR = 'abcd'


def test() -> str:
    """Example internal function."""
    return 'ok1'


class MhEg (object):
    """Example internal class."""

    def run_mh_eg(self) -> int:
        """Example member function of an internal class."""
        return 10

    def slow(self) -> None:
        """An example slow function."""
        t = 3
        time.sleep(t)
        return

    def call_external_func(self) -> None:
        """No documentation."""
        x = l2.L2Mh()
        y = x.slow()
        return y


if __name__ == '__main__':
    pass
