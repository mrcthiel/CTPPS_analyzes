sshfs mthiel@uerjpowerp100.cern.ch:/storage1/mthiel/WW_exc_noPU_miniAOD_900pre4/ mount/
ls mount/ > files.txt
cmsRun python/step1_cfg.py


fusermount -u mount


