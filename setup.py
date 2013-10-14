from distutils.core import setup, Extension

module1 = Extension('cube',
                    sources = ['cube_wrapper.cpp'])

setup (name = 'cube',
       version = '1.0',
       description = 'magic cube package',
       ext_modules = [module1])