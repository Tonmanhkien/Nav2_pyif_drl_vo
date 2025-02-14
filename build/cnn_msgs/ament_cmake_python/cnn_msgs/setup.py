from setuptools import find_packages
from setuptools import setup

setup(
    name='cnn_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('cnn_msgs', 'cnn_msgs.*')),
)
