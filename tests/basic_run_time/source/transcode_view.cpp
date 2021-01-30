// =============================================================================
//
// ztd.text
// Copyright © 2021 JeanHeyd "ThePhD" Meneide and Shepherd's Oasis, LLC
// Contact: opensource@soasis.org
//
// Commercial License Usage
// Licensees holding valid commercial ztd.text licenses may use this file in
// accordance with the commercial license agreement provided with the
// Software or, alternatively, in accordance with the terms contained in
// a written agreement between you and Shepherd's Oasis, LLC.
// For licensing terms and conditions see your agreement. For
// further information contact opensource@soasis.org.
//
// Apache License Version 2 Usage
// Alternatively, this file may be used under the terms of Apache License
// Version 2.0 (the "License") for non-commercial use; you may not use this
// file except in compliance with the License. You may obtain a copy of the 
// License at
//
//		http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// =============================================================================

#include <ztd/text/transcode_view.hpp>

#include <catch2/catch.hpp>

#include <ztd/text/tests/basic_unicode_strings.hpp>

template <typename FromEncoding, typename ToEncoding, typename Input, typename Expected>
void check_transcode_view(const Input& input, const Expected& expected_output) {
	ztd::text::transcode_view<FromEncoding, ToEncoding> result0_view(input);
	auto result0_it         = result0_view.begin();
	const auto result0_last = result0_view.end();
	auto truth0_it          = std::cbegin(expected_output);
	const auto truth0_last  = std::cend(expected_output);
	for (; result0_it != result0_last; ++result0_it, (void)++truth0_it) {
		REQUIRE(truth0_it != truth0_last);
		const auto truth0_val  = *truth0_it;
		const auto result0_val = *result0_it;
		REQUIRE(truth0_val == result0_val);
	}
}

TEST_CASE("text/transcode_view/basic", "basic usages of encode_view type do not explode") {
	SECTION("execution") {
		SECTION("execution") {
			check_transcode_view<ztd::text::execution, ztd::text::execution>(
			     ztd::text::tests::ansi_sequence_truth, ztd::text::tests::ansi_sequence_truth);
			check_transcode_view<ztd::text::execution, ztd::text::execution>(
			     ztd::text::tests::unicode_sequence_truth, ztd::text::tests::unicode_sequence_truth);
		}
		SECTION("wide_execution") {
			check_transcode_view<ztd::text::execution, ztd::text::wide_execution>(
			     ztd::text::tests::ansi_sequence_truth, ztd::text::tests::w_ansi_sequence_truth);
			check_transcode_view<ztd::text::execution, ztd::text::wide_execution>(
			     ztd::text::tests::unicode_sequence_truth, ztd::text::tests::w_unicode_sequence_truth);
		}
		SECTION("utf8") {
			check_transcode_view<ztd::text::execution, ztd::text::utf8>(
			     ztd::text::tests::ansi_sequence_truth, ztd::text::tests::u8_ansi_sequence_truth);
			check_transcode_view<ztd::text::execution, ztd::text::utf8>(
			     ztd::text::tests::unicode_sequence_truth, ztd::text::tests::u8_unicode_sequence_truth);
		}
		SECTION("utf16") {
			check_transcode_view<ztd::text::execution, ztd::text::utf16>(
			     ztd::text::tests::ansi_sequence_truth, ztd::text::tests::u16_ansi_sequence_truth);
			check_transcode_view<ztd::text::execution, ztd::text::utf16>(
			     ztd::text::tests::unicode_sequence_truth, ztd::text::tests::u16_unicode_sequence_truth);
		}
		SECTION("utf32") {
			check_transcode_view<ztd::text::execution, ztd::text::utf32>(
			     ztd::text::tests::ansi_sequence_truth, ztd::text::tests::u32_ansi_sequence_truth);
			check_transcode_view<ztd::text::execution, ztd::text::utf32>(
			     ztd::text::tests::unicode_sequence_truth, ztd::text::tests::u32_unicode_sequence_truth);
		}
	}
	SECTION("wide_execution") {
		SECTION("execution") {
			check_transcode_view<ztd::text::wide_execution, ztd::text::execution>(
			     ztd::text::tests::w_ansi_sequence_truth, ztd::text::tests::ansi_sequence_truth);
			check_transcode_view<ztd::text::wide_execution, ztd::text::execution>(
			     ztd::text::tests::w_unicode_sequence_truth, ztd::text::tests::unicode_sequence_truth);
		}
		SECTION("wide_execution") {
			check_transcode_view<ztd::text::wide_execution, ztd::text::wide_execution>(
			     ztd::text::tests::w_ansi_sequence_truth, ztd::text::tests::w_ansi_sequence_truth);
			check_transcode_view<ztd::text::wide_execution, ztd::text::wide_execution>(
			     ztd::text::tests::w_unicode_sequence_truth, ztd::text::tests::w_unicode_sequence_truth);
		}
		SECTION("utf8") {
			check_transcode_view<ztd::text::wide_execution, ztd::text::utf8>(
			     ztd::text::tests::w_ansi_sequence_truth, ztd::text::tests::u8_ansi_sequence_truth);
			check_transcode_view<ztd::text::wide_execution, ztd::text::utf8>(
			     ztd::text::tests::w_unicode_sequence_truth, ztd::text::tests::u8_unicode_sequence_truth);
		}
		SECTION("utf16") {
			check_transcode_view<ztd::text::wide_execution, ztd::text::utf16>(
			     ztd::text::tests::w_ansi_sequence_truth, ztd::text::tests::u16_ansi_sequence_truth);
			check_transcode_view<ztd::text::wide_execution, ztd::text::utf16>(
			     ztd::text::tests::w_unicode_sequence_truth, ztd::text::tests::u16_unicode_sequence_truth);
		}
		SECTION("utf32") {
			check_transcode_view<ztd::text::wide_execution, ztd::text::utf32>(
			     ztd::text::tests::w_ansi_sequence_truth, ztd::text::tests::u32_ansi_sequence_truth);
			check_transcode_view<ztd::text::wide_execution, ztd::text::utf32>(
			     ztd::text::tests::w_unicode_sequence_truth, ztd::text::tests::u32_unicode_sequence_truth);
		}
	}
	SECTION("utf8") {
		SECTION("execution") {
			check_transcode_view<ztd::text::utf8, ztd::text::execution>(
			     ztd::text::tests::u8_ansi_sequence_truth, ztd::text::tests::ansi_sequence_truth);
			check_transcode_view<ztd::text::utf8, ztd::text::execution>(
			     ztd::text::tests::u8_unicode_sequence_truth, ztd::text::tests::unicode_sequence_truth);
		}
		SECTION("wide_execution") {
			check_transcode_view<ztd::text::utf8, ztd::text::wide_execution>(
			     ztd::text::tests::u8_ansi_sequence_truth, ztd::text::tests::w_ansi_sequence_truth);
			check_transcode_view<ztd::text::utf8, ztd::text::wide_execution>(
			     ztd::text::tests::u8_unicode_sequence_truth, ztd::text::tests::w_unicode_sequence_truth);
		}
		SECTION("utf8") {
			check_transcode_view<ztd::text::utf8, ztd::text::utf8>(
			     ztd::text::tests::u8_ansi_sequence_truth, ztd::text::tests::u8_ansi_sequence_truth);
			check_transcode_view<ztd::text::utf8, ztd::text::utf8>(
			     ztd::text::tests::u8_unicode_sequence_truth, ztd::text::tests::u8_unicode_sequence_truth);
		}
		SECTION("utf16") {
			check_transcode_view<ztd::text::utf8, ztd::text::utf16>(
			     ztd::text::tests::u8_ansi_sequence_truth, ztd::text::tests::u16_ansi_sequence_truth);
			check_transcode_view<ztd::text::utf8, ztd::text::utf16>(
			     ztd::text::tests::u8_unicode_sequence_truth, ztd::text::tests::u16_unicode_sequence_truth);
		}
		SECTION("utf32") {
			check_transcode_view<ztd::text::utf8, ztd::text::utf32>(
			     ztd::text::tests::u8_ansi_sequence_truth, ztd::text::tests::u32_ansi_sequence_truth);
			check_transcode_view<ztd::text::utf8, ztd::text::utf32>(
			     ztd::text::tests::u8_unicode_sequence_truth, ztd::text::tests::u32_unicode_sequence_truth);
		}
	}
	SECTION("utf16") {
		SECTION("execution") {
			check_transcode_view<ztd::text::utf16, ztd::text::execution>(
			     ztd::text::tests::u16_ansi_sequence_truth, ztd::text::tests::ansi_sequence_truth);
			check_transcode_view<ztd::text::utf16, ztd::text::execution>(
			     ztd::text::tests::u16_unicode_sequence_truth, ztd::text::tests::unicode_sequence_truth);
		}
		SECTION("wide_execution") {
			check_transcode_view<ztd::text::utf16, ztd::text::wide_execution>(
			     ztd::text::tests::u16_ansi_sequence_truth, ztd::text::tests::w_ansi_sequence_truth);
			check_transcode_view<ztd::text::utf16, ztd::text::wide_execution>(
			     ztd::text::tests::u16_unicode_sequence_truth, ztd::text::tests::w_unicode_sequence_truth);
		}
		SECTION("utf8") {
			check_transcode_view<ztd::text::utf16, ztd::text::utf8>(
			     ztd::text::tests::u16_ansi_sequence_truth, ztd::text::tests::u8_ansi_sequence_truth);
			check_transcode_view<ztd::text::utf16, ztd::text::utf8>(
			     ztd::text::tests::u16_unicode_sequence_truth, ztd::text::tests::u8_unicode_sequence_truth);
		}
		SECTION("utf16") {
			check_transcode_view<ztd::text::utf16, ztd::text::utf16>(
			     ztd::text::tests::u16_ansi_sequence_truth, ztd::text::tests::u16_ansi_sequence_truth);
			check_transcode_view<ztd::text::utf16, ztd::text::utf16>(
			     ztd::text::tests::u16_unicode_sequence_truth, ztd::text::tests::u16_unicode_sequence_truth);
		}
		SECTION("utf32") {
			check_transcode_view<ztd::text::utf16, ztd::text::utf32>(
			     ztd::text::tests::u16_ansi_sequence_truth, ztd::text::tests::u32_ansi_sequence_truth);
			check_transcode_view<ztd::text::utf16, ztd::text::utf32>(
			     ztd::text::tests::u16_unicode_sequence_truth, ztd::text::tests::u32_unicode_sequence_truth);
		}
	}
	SECTION("utf32") {
		SECTION("execution") {
			check_transcode_view<ztd::text::utf32, ztd::text::execution>(
			     ztd::text::tests::u32_ansi_sequence_truth, ztd::text::tests::ansi_sequence_truth);
			check_transcode_view<ztd::text::utf32, ztd::text::execution>(
			     ztd::text::tests::u32_unicode_sequence_truth, ztd::text::tests::unicode_sequence_truth);
		}
		SECTION("wide_execution") {
			check_transcode_view<ztd::text::utf32, ztd::text::wide_execution>(
			     ztd::text::tests::u32_ansi_sequence_truth, ztd::text::tests::w_ansi_sequence_truth);
			check_transcode_view<ztd::text::utf32, ztd::text::wide_execution>(
			     ztd::text::tests::u32_unicode_sequence_truth, ztd::text::tests::w_unicode_sequence_truth);
		}
		SECTION("utf8") {
			check_transcode_view<ztd::text::utf32, ztd::text::utf8>(
			     ztd::text::tests::u32_ansi_sequence_truth, ztd::text::tests::u8_ansi_sequence_truth);
			check_transcode_view<ztd::text::utf32, ztd::text::utf8>(
			     ztd::text::tests::u32_unicode_sequence_truth, ztd::text::tests::u8_unicode_sequence_truth);
		}
		SECTION("utf16") {
			check_transcode_view<ztd::text::utf32, ztd::text::utf16>(
			     ztd::text::tests::u32_ansi_sequence_truth, ztd::text::tests::u16_ansi_sequence_truth);
			check_transcode_view<ztd::text::utf32, ztd::text::utf16>(
			     ztd::text::tests::u32_unicode_sequence_truth, ztd::text::tests::u16_unicode_sequence_truth);
		}
		SECTION("utf32") {
			check_transcode_view<ztd::text::utf32, ztd::text::utf32>(
			     ztd::text::tests::u32_ansi_sequence_truth, ztd::text::tests::u32_ansi_sequence_truth);
			check_transcode_view<ztd::text::utf32, ztd::text::utf32>(
			     ztd::text::tests::u32_unicode_sequence_truth, ztd::text::tests::u32_unicode_sequence_truth);
		}
	}
}