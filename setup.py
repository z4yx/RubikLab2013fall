from distutils.core import setup, Extension

module1 = Extension('cube',
                    sources = [
                    'cube_simplify.cpp',
                    'cube_wrapper.cpp',
                    'cube_model.cpp',
					'cube_step_one.cpp',
					'step_final.cpp',
					'step_layer2.cpp',
					'step_up_face.cpp'
                    ]
                   )

setup (name = 'cube',
       version = '1.0',
       description = 'magic cube package',
       ext_modules = [module1])