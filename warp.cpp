#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;


map<float, float> beats = {};
map<float, float> samples = {};

float endTempo;
void shtoMarker(float beat, float sample);
float b2s(float beat);
float s2b(float sample);

int main() {

	string str;
	string strBeat;
	string strSample;
	float beat;
	float sample;
	string strTempo;
	string s;
	string b;

	cout << "Jepe beat1 : ";
	cin >> strBeat;
	beat = stod(strBeat);

	cout << "Jepe sample1: ";
	cin >> strSample;
	sample = stod(strSample);
	shtoMarker(beat, sample);

	cout << "Jepe beat2 : ";
	cin >> strBeat;
	beat = stod(strBeat);

	cout << "Jepe sample2: ";
	cin >> strSample;
	sample = stod(strSample);
	shtoMarker(beat, sample);



	cout << "Jepe end_tempo: ";
	cin >> strTempo;
	endTempo = stod(strTempo);

	cout << "Jepe s2b = ";
	cin >> s;

	cout << "Jepe b2s = ";
	cin >> b;

	cout << "Rezultatet"
		<< endl
		<< "s2b = "
		<< s2b(stod(s))
		<< endl
		<< "b2s = "
		<< b2s(stod(b))
		<< endl;
}

void shtoMarker(float beat, float sample)
{
	beats[beat] = sample;
	samples[sample] = beat;
}

float b2s(float beat)
{
	auto marker2 = beats.upper_bound(beat);

	if (marker2 == beats.begin()) marker2 = next(marker2);

	auto marker1 = prev(marker2);

	auto beatIPare = marker1->first;
	auto sampleIPare = marker1->second;

	float tempo;

	if (marker2 == beats.end()) {
		tempo = endTempo;
	}
	else {
		auto secondBeat = marker2->first;
		auto secondSample = marker2->second;

		tempo = (secondBeat - beatIPare) / (secondSample - sampleIPare);
	}

	return sampleIPare + ((beat - beatIPare) + tempo);
}

float s2b(float sample)
{
	auto marker2 = samples.upper_bound(sample);
	if (marker2 == samples.begin()) marker2 = next(marker2);
	auto marker1 = prev(marker2);

	auto firstBeat = marker1->second;
	auto firstSample = marker1->first;

	float tempo;

	if (marker2 == samples.end()) {
		tempo = endTempo;
	}
	else {
		auto beatIDyte = marker2->second;
		auto sampleIDyte = marker2->first;
		tempo = (beatIDyte - firstBeat) / (sampleIDyte - firstSample);
	}

	return firstBeat + ((sample -
		firstSample) + tempo);
}
