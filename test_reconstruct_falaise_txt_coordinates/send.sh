#!/bin/sh

#SBATCH --job-name=0nubb_Se82_10p2eve_single_job         	 
#SBATCH --mem=2G                     	 
#SBATCH --licenses=sps                   
#SBATCH --time=10:00                 	 
#SBATCH --cpus-per-task=1               

source ${THRONG_DIR}/config/supernemo_profile.bash
snswmgr_load_setup falaise@5.1.5

FALAISE_BIN=/sps/nemo/sw/redhat-9-x86_64/snsw/opt2/falaise-5.1.5/bin
WORKDIR=/sps/nemo/scratch/ykozina/Falaise/tutorial/kink-track-study---Anna/0nu

#$FALAISE_BIN/flsimulate -c $WORKDIR/simu_setup.conf -o $WORKDIR/simu_cut1_test.brio

$FALAISE_BIN/flreconstruct -i $WORKDIR/simu_cut1_test.brio -p reco.conf -o $WORKDIR/reco_cut1_test_data_source_output_falaise_source_data.brio
