#!/usr/bin/env bash

set -o errexit

function print_help {
  echo "usage: $0 [-v, --verbose | -h, --help] path"
}

while [[ $# > 0 ]]
do
case $1 in
    -v|--verbose)
    VERBOSE=true
    shift
    ;;
    -h|--help)
    print_help
    exit 0
    ;;
    --) # end of all options
    shift
    break
    ;;
    -*) # unknown option
    echo "Error: Unknown option: $1" >&2
	  exit 1
    ;;
    *) # no more options
    break
    ;;
esac
done

function set_verbose_output {
  if [ $VERBOSE ]; then
    set -o xtrace
    set +o verbose
  fi
}

if [[ $# > 0 ]]; then
  DIR=$1
else
  echo "Error: no path specified"
  print_help
  exit 1
fi

set_verbose_output

MASTER_DIR=checkout

GIT_REPO_HEAD_SHA=$(git rev-parse --short HEAD)
GIT_REPO_REMOTE_URL=$(git config --get remote.origin.url)
GIT_MASTER_BRANCH=master
GIT_DEPLOY_BRANCH=gh-pages
GIT_SUBTREE_OPTS="--git-dir=$DIR/.git --work-tree=$DIR"

rm -rf $DIR

git clone -b $GIT_MASTER_BRANCH --single-branch $GIT_REPO_REMOTE_URL $MASTER_DIR
pushd $MASTER_DIR

yarn install
yarn build

mkdir -p $DIR
git clone -b $GIT_DEPLOY_BRANCH --single-branch $GIT_REPO_REMOTE_URL $DIR

git $GIT_SUBTREE_OPTS rm -r .

rsync -av build/ $DIR

git $GIT_SUBTREE_OPTS add -A .
git $GIT_SUBTREE_OPTS commit -am "deploy release of ${GIT_REPO_HEAD_SHA}"
git $GIT_SUBTREE_OPTS push origin $GIT_DEPLOY_BRANCH

popd
# Cleanup
rm -rf $MASTER_DIR
