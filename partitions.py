from os.path import join, isfile
from shutil import copyfile
Import("env")
platform = env.PioPlatform()
FRAMEWORK_DIR = platform.get_package_dir("framework-arduinoespressif32")
destinationfile = join(
	FRAMEWORK_DIR, "tools", "partitions",
	"%s.csv" % env.BoardConfig().get("build.partitions", "default")
)
partitionsfile = join(
	env.get("PROJECT_DIR"),
	"%s.csv" % env.BoardConfig().get("build.partitions", "default")
)
copyfile(partitionsfile, destinationfile)
