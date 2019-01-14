//
// Created by mufengjun260 on 17-12-22.
//

#include "MatchSaver.h"

/**
 * save result of token matching
 * @param matchFile found code stack which was clone from targetFile in this file
 * @param targetFile was copied some code by matchFile
 * @param startMatchLine
 * @param endMatchLine
 * @param startTargetLine
 * @param endTargetLine
 */

MatchSaver::MatchSaver(string matchFile, string targetFile, int startMatchLine, int endMatchLine, int startTargetLine,
                       int endTargetLine, int totalMatchLine, int totalTargetLine, int blockNum) {
    this->matchFile = matchFile;
    this->targetFile = targetFile;
    this->startMatchLine = startMatchLine;
    this->endMatchLine = endMatchLine;
    this->startTargetLine = startTargetLine;
    this->endTargetLine = endTargetLine;
    this->totalMatchLine = totalMatchLine;
    this->totalTargetLine = totalTargetLine;
    this->blockNum = blockNum;
}

const string &MatchSaver::getMatchFile() const {
    return matchFile;
}

const string &MatchSaver::getTargetFile() const {
    return targetFile;
}

int MatchSaver::getStartMatchLine() const {
    return startMatchLine;
}

int MatchSaver::getEndMatchLine() const {
    return endMatchLine;
}

int MatchSaver::getStartTargetLine() const {
    return startTargetLine;
}

int MatchSaver::getEndTargetLine() const {
    return endTargetLine;
}

int MatchSaver::getTotalTargetLine() const {
    return totalTargetLine;
}

int MatchSaver::getTotalMatchLine() const {
    return totalMatchLine;
}

int MatchSaver::getBlockNum() const {
    return blockNum;
}

void MatchSaver::setEndMatchLine(int endMatchLine) {
	MatchSaver::endMatchLine = endMatchLine;
}

void MatchSaver::setEndTargetLine(int endTargetLine) {
	MatchSaver::endTargetLine = endTargetLine;
}

void MatchSaver::setMatchFile(const string &matchFile) {
	MatchSaver::matchFile = matchFile;
}

void MatchSaver::setTargetFile(const string &targetFile) {
	MatchSaver::targetFile = targetFile;
}

void MatchSaver::setBlockNum(int blockNum) {
	MatchSaver::blockNum = blockNum;
}

void MatchSaver::setStartMatchLine(int startMatchLine) {
	MatchSaver::startMatchLine = startMatchLine;
}

void MatchSaver::setStartTargetLine(int startTargetLine) {
	MatchSaver::startTargetLine = startTargetLine;
}
